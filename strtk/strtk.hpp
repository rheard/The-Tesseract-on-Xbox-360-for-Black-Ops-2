/*
 *****************************************************************
 *                     String Toolkit Library                    *
 *                                                               *
 * Author: Arash Partow (2002-2012)                              *
 * URL: http://www.partow.net/programming/strtk/index.html       *
 *                                                               *
 * Copyright notice:                                             *
 * Free use of the String Toolkit Library is permitted under the *
 * guidelines and in accordance with the most current version of *
 * the Common Public License.                                    *
 * http://www.opensource.org/licenses/cpl1.0.php                 *
 *                                                               *
 *****************************************************************
*/

#ifndef INCLUDE_STRTK_HPP
#define INCLUDE_STRTK_HPP

#include <iterator>
#include <string>
#include <list>
#include <set>
#include <stack>
#include <queue>

namespace strtk
{
   static const std::size_t one_kilobyte = 1024;

   namespace details
   {
      struct not_supported_type_tag   {};
      struct unsigned_type_tag        {};
      struct signed_type_tag          {};
      struct real_type_tag            {};
      struct byte_type_tag            {};
      struct bool_type_tag            {};
      struct hex_number_type_tag      {};
      struct hex_string_type_tag      {};
      struct base64_type_tag          {};
      struct ignore_token_type_tag    {};
      struct stdstring_type_tag       {};
      struct stdstring_range_type_tag {};
      struct value_type_tag           {};
      struct sink_type_tag            {};
      struct stl_seq_type_tag         {};
      struct attribute_type_tag       {};
      struct semantic_action_type_tag {};
      struct expect_type_tag          {};
      struct like_type_tag            {};
      struct inrange_type_tag         {};
      struct trim_type_tag            {};
      struct lcase_type_tag           {};
      struct ucase_type_tag           {};
      struct fillchararray_type_tag   {};

      template <typename T>
      struct supported_conversion_to_type
      {
         typedef not_supported_type_tag type;
      };

      template <typename T>
      struct supported_conversion_from_type
      {
         typedef not_supported_type_tag type;
      };

      template <bool, typename T = void>
      struct enable_if {};

      template <typename T>
      struct enable_if<true, T> { typedef T type; };

      template <typename T>
      struct supported_iterator_type
      {
         enum { value = false };
      };

      template <typename T>
      struct is_valid_iterator
      {
         typedef typename details::enable_if<details::supported_iterator_type<T>::value,T>::type type;
      };

      template <typename T> struct numeric;
      template <typename T> inline std::size_t type_length(const T&);

      struct no_t  {};
      struct yes_t {};

      template <typename T>
      struct is_pod
      {
         typedef no_t result_t;
         enum { result = false };
      };

      template <typename T>
      struct is_stl_container
      { typedef no_t result_t; };

      #define register_stl_container1(C) \
      template <typename T1, typename T2>struct is_stl_container<C<T1,T2> >{ typedef yes_t result_t; };

      #define register_stl_container2(C) \
      template <typename T1, typename T2, typename T3>struct is_stl_container<C<T1,T2,T3> >{ typedef yes_t result_t; };

      register_stl_container1(std::vector)
      register_stl_container1(std::deque)
      register_stl_container1(std::list)
      register_stl_container1(std::queue)
      register_stl_container1(std::stack)
      register_stl_container2(std::set)
      register_stl_container2(std::multiset)
      register_stl_container2(std::priority_queue)

      #undef register_stl_container1
      #undef register_stl_container2

   } // namespace details

   template <typename Iterator, typename T>
   inline bool string_to_type_converter(const Iterator begin, const Iterator end, T& t)
   {
      typedef typename details::is_valid_iterator<Iterator>::type itr_type;
      typename details::supported_conversion_to_type<T>::type type;
      Iterator itr = begin;
      return string_to_type_converter_impl(itr,end,t,type);
   }

   template <typename Iterator, typename T>
   inline bool string_to_type_converter(const std::pair<Iterator,Iterator>& range, T& t)
   {
      return string_to_type_converter(range.first,range.second,t);
   }

   template <typename T, typename Iterator>
   inline T string_to_type_converter(const Iterator begin, const Iterator end)
   {
      typedef typename details::is_valid_iterator<Iterator>::type itr_type;
      typename details::supported_conversion_to_type<T>::type type;
      T t;
      Iterator itr = begin;
      if (string_to_type_converter_impl(itr,end,t,type))
         return t;
      else
         throw std::invalid_argument("string_to_type_converter() - Failed to convert: " +
                                     std::string(begin,end));
   }

   template <typename T, typename Iterator>
   inline T string_to_type_converter(const std::pair<Iterator,Iterator>& range)
   {
      return string_to_type_converter<T>(range.first,range.second);
   }

   template <typename T>
   inline bool string_to_type_converter(const std::string& s, T& t)
   {
      return string_to_type_converter<const char*,T>(s.data(),s.data() + s.size(),t);
   }

   template <typename T>
   inline T string_to_type_converter(const std::string& s)
   {
      return string_to_type_converter<T>(s.data(),s.data() + s.size());
   }

   namespace range
   {
      template <typename T>
      class adapter
      {
      public:

         typedef T value_type;
         typedef T* iterator;
         typedef const iterator const_iterator;

         adapter(T* const begin, T* const end)
         : begin_(begin),
           end_(end)
         {}

         adapter(const std::pair<T*,T*>& r)
         : begin_(r.first),
           end_(r.second)
         {}

         adapter(T* const begin, const std::size_t length)
         : begin_(begin),
           end_(begin_ + length)
         {}

         inline iterator begin() const
         {
            return begin_;
         }

         inline iterator end() const
         {
            return end_;
         }

         inline std::size_t size() const
         {
            return std::distance(begin_,end_);
         }

         inline operator std::string() const
         {
            return stringify(begin_,end_);
         }

         inline const T& operator[](const std::size_t& index) const
         {
            return *(begin_ + index);
         }

         inline T& operator[](const std::size_t& index)
         {
            return *(begin_ + index);
         }

      private:

         template <typename Type>
         static inline std::string stringify(Type*,Type*)
         {
            static std::string result = "";
            return result;
         }

         static inline std::string stringify(const char* begin, const char* end)
         {
            return std::string(begin,end);
         }

         iterator begin_;
         iterator end_;
      };

      typedef adapter<const char> string;
      typedef adapter<const unsigned char> ustring;

      template <typename T>
      inline adapter<T> type(const T* begin, const T* end)
      {
         return adapter<T>(begin,end);
      }

      template <typename T, std::size_t N>
      inline adapter<T> type(const T (&t)[N])
      {
         return adapter<T>(t,N);
      }

      static inline adapter<const char> type(const std::string& s)
      {
         return adapter<const char>(s.data(),s.size());
      }

      template <typename T,
                typename Allocator,
                template <typename,typename> class Sequence>
      inline adapter<typename Sequence<T,Allocator>::iterator> type(const Sequence<T,Allocator>& seq)
      {
         return adapter<typename Sequence<T,Allocator>::iterator>(seq.begin(),seq.end());
      }

      inline std::string as_string(const adapter<const char>& a)
      {
         return std::string(a.begin(),a.end());
      }

      inline std::string as_string(const adapter<const unsigned char>& a)
      {
         return std::string(a.begin(),a.end());
      }

   } // namespace range

   template <typename T>
   struct single_delimiter_predicate
   {
   public:

      typedef T value_type;

      single_delimiter_predicate(const T& d)
      : delimiter_(d)
      {}

      inline bool operator()(const T& d) const
      {
         return delimiter_ == d;
      }

   private:

      single_delimiter_predicate<T>& operator=(const single_delimiter_predicate<T>&);
      const T delimiter_;
   };

   struct multiple_char_delimiter_predicate
   {
   public:

      template <typename Iterator>
      multiple_char_delimiter_predicate(const Iterator begin, const Iterator end)
      {
         setup_delimiter_table(begin,end);
      }

      multiple_char_delimiter_predicate(const std::string& s)
      {
         setup_delimiter_table(s.data(),s.data() + s.size());
      }

      inline bool operator()(const unsigned char& c) const
      {
         return (delimiter_table_[c]);
      }

      inline bool operator()(const char& c) const
      {
         return operator()(static_cast<unsigned char>(c));
      }

   private:

      static const std::size_t table_size = 256;

      template <typename Iterator>
      inline void setup_delimiter_table(const Iterator begin, const Iterator end)
      {
         std::fill_n(delimiter_table_,table_size,false);
         for (Iterator itr = begin; itr != end; ++itr)
         {
            delimiter_table_[static_cast<unsigned char>(*itr)] = true;
         }
      }

      bool delimiter_table_[table_size];
   };

   namespace details
   {
      template <typename Allocator,
                template <typename,typename> class Sequence>
      struct index_remover_impl
      {
         typedef Sequence<std::size_t,Allocator> sequence_t;
         index_remover_impl(const sequence_t& sequence)
         : itr_(sequence.begin()),
           end_(sequence.end()),
           current_index_(0),
           check_(true)
         {}

         template <typename T>
         inline bool operator()(const T&)
         {
            if (check_)
            {
               if (current_index_++ == *itr_)
               {
                  if (end_ == ++itr_)
                  {
                     check_ = false;
                  }
                  return true;
               }
            }
            return false;
         }

         typename sequence_t::const_iterator itr_;
         typename sequence_t::const_iterator end_;
         std::size_t current_index_;
         bool check_;
      };
   }

   template <typename Allocator,
             template <typename,typename> class Sequence>
   inline details::index_remover_impl<Allocator,Sequence> index_remover(const Sequence<std::size_t,Allocator>& sequence)
   {
      return details::index_remover_impl<Allocator,Sequence>(sequence);
   }

   template <typename Iterator, typename Predicate>
   inline std::size_t remove_inplace(Predicate predicate,
                                     Iterator begin,
                                     Iterator end)
   {
      Iterator itr1 = begin;
      Iterator itr2 = begin;
      std::size_t removal_count = 0;
      while (end != itr1)
      {
         if (predicate(*itr1))
         {
            ++itr1;
            ++removal_count;
         }
         else
         {
            if (itr1 != itr2)
            {
               (*itr2) = (*itr1);
            }
            ++itr1;
            ++itr2;
         }
      }
      return removal_count;
   }

   template <typename T, typename Predicate>
   inline std::size_t remove_inplace(Predicate predicate, const range::adapter<T>& r)
   {
      return remove_inplace(predicate,r.begin(),r.end());
   }

   template <typename Predicate,
             typename T,
             typename Allocator,
             template <typename,typename> class Sequence>
   inline std::size_t remove_inplace(Predicate predicate, Sequence<T,Allocator>& sequence)
   {
      const std::size_t removal_count = remove_inplace(predicate,sequence.begin(),sequence.end());
      sequence.resize(sequence.size() - removal_count);
      return removal_count;
   }

   inline void remove_inplace(const std::string::value_type c, std::string& s)
   {
      const std::size_t removal_count = remove_inplace(single_delimiter_predicate<std::string::value_type>(c),
                                                       const_cast<char*>(s.data()),
                                                       const_cast<char*>(s.data() + s.size()));
      if (removal_count > 0)
      {
         s.resize(s.size() - removal_count);
      }
   }

   template <typename Predicate>
   inline void remove_inplace(Predicate predicate, std::string& s)
   {
      const std::size_t removal_count = remove_inplace(predicate,
                                                       const_cast<char*>(s.data()),
                                                       const_cast<char*>(s.data() + s.size()));
      if (removal_count > 0)
      {
         s.resize(s.size() - removal_count);
      }
   }

   namespace details
   {
      #if (defined(__MINGW32_VERSION)) ||\
          (defined(__APPLE__) && (__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ < 1070)) ||\
          (defined(_WIN32) && (_MSC_VER < 1400))
         inline std::size_t strnlength(const char* s, const std::size_t& n)
         {
            const char *end = reinterpret_cast<const char*>(memchr(s, '\0', n));
            return end ? (size_t) (end - s) : n;
         }
      #else
         inline std::size_t strnlength(const char* s, const std::size_t& n)
         {
            return strnlen(s,n);
         }
      #endif
   }

   template <typename Iterator, typename Predicate>
   inline std::size_t remove_trailing(Predicate predicate,
                                      Iterator begin,
                                      Iterator end)
   {
      const std::size_t length = std::distance(begin,end);
      if (0 == length)
         return 0;
      Iterator itr = begin + (length - 1);
      std::size_t removal_count = 0;

      while ((begin != itr) && predicate(*itr))
      {
         --itr;
         ++removal_count;
      }

      return removal_count;
   }

   template <typename T, typename Predicate>
   inline std::size_t remove_trailing(Predicate predicate, const range::adapter<T>& r)
   {
      return remove_trailing(predicate,r.begin(),r.end());
   }

   inline void remove_trailing(const std::string::value_type c, std::string& s)
   {
      if (s.empty()) return;
      const std::size_t removal_count = remove_trailing(single_delimiter_predicate<std::string::value_type>(c),
                                                        const_cast<char*>(s.data()),
                                                        const_cast<char*>(s.data() + s.size()));
      if (removal_count > 0)
      {
         s.resize(s.size() - removal_count);
      }
   }

   inline void remove_trailing(const std::string& rem_chars, std::string& s)
   {
      if (s.empty()) return;
      const std::size_t removal_count = remove_trailing(multiple_char_delimiter_predicate(rem_chars),
                                                        const_cast<char*>(s.data()),
                                                        const_cast<char*>(s.data() + s.size()));
      if (removal_count > 0)
      {
         s.resize(s.size() - removal_count);
      }
   }

   inline void remove_trailing(const char* rem_chars, std::string& s)
   {
      const std::size_t removal_count = remove_trailing(multiple_char_delimiter_predicate(
                                                        rem_chars,
                                                        rem_chars + details::strnlength(rem_chars,256)),
                                                        const_cast<char*>(s.data()),
                                                        const_cast<char*>(s.data() + s.size()));
      if (removal_count > 0)
      {
         s.resize(s.size() - removal_count);
      }
   }

   template <typename Predicate>
   inline void remove_trailing(Predicate predicate, std::string& s)
   {
      if (s.empty()) return;
      const std::size_t removal_count = remove_trailing(predicate,
                                                        const_cast<char*>(s.data()),
                                                        const_cast<char*>(s.data() + s.size()));
      if (removal_count > 0)
      {
         s.resize(s.size() - removal_count);
      }
   }

   template <typename Iterator, typename Predicate>
   inline std::size_t remove_leading(Predicate predicate,
                                     Iterator begin,
                                     Iterator end)
   {
      const std::size_t length = std::distance(begin,end);
      if (0 == length)
         return 0;
      Iterator itr = begin;
      std::size_t removal_count = 0;

      while ((end != itr) && predicate(*itr))
      {
         ++itr;
         ++removal_count;
      }

      std::copy(itr,end,begin);
      return removal_count;
   }

   template <typename T, typename Predicate>
   inline std::size_t remove_leading(Predicate predicate, const range::adapter<T>& r)
   {
      return remove_leading(predicate,r.begin(),r.end());
   }

   inline void remove_leading(const std::string::value_type c, std::string& s)
   {
      if (s.empty()) return;
      const std::size_t removal_count = remove_leading(single_delimiter_predicate<std::string::value_type>(c),
                                                       const_cast<char*>(s.data()),
                                                       const_cast<char*>(s.data() + s.size()));
      if (removal_count > 0)
      {
         s.resize(s.size() - removal_count);
      }
   }

   inline void remove_leading(const std::string& rem_chars, std::string& s)
   {
      if (s.empty()) return;
      const std::size_t removal_count = remove_leading(multiple_char_delimiter_predicate(rem_chars),
                                                       const_cast<char*>(s.data()),
                                                       const_cast<char*>(s.data() + s.size()));
      if (removal_count > 0)
      {
         s.resize(s.size() - removal_count);
      }
   }

   inline void remove_leading(const char* rem_chars, std::string& s)
   {
      if (s.empty()) return;
      const std::size_t removal_count = remove_leading(multiple_char_delimiter_predicate(
                                                       rem_chars,
                                                       rem_chars + details::strnlength(rem_chars,256)),
                                                       const_cast<char*>(s.data()),
                                                       const_cast<char*>(s.data() + s.size()));
      if (removal_count > 0)
      {
         s.resize(s.size() - removal_count);
      }
   }

   inline void remove_leading_trailing(const std::string& rem_chars, std::string& s)
   {
      remove_leading(rem_chars,s);
      remove_trailing(rem_chars,s);
   }

   template <typename Predicate>
   inline void remove_leading(Predicate predicate, std::string& s)
   {
      if (s.empty()) return;
      const std::size_t removal_count = remove_leading(predicate,
                                                       const_cast<char*>(s.data()),
                                                       const_cast<char*>(s.data() + s.size()));
      if (removal_count > 0)
      {
         s.resize(s.size() - removal_count);
      }
   }

   template <typename Iterator>
   inline bool match(const Iterator pattern_begin,
                     const Iterator pattern_end,
                     const Iterator data_begin,
                     const Iterator data_end,
                     const typename std::iterator_traits<Iterator>::value_type& zero_or_more,
                     const typename std::iterator_traits<Iterator>::value_type& zero_or_one)
   {
      if (0 == std::distance(data_begin,data_end)) return false;

      Iterator d_itr = data_begin;
      Iterator p_itr = pattern_begin;
      Iterator c_itr = data_begin;
      Iterator m_itr = data_begin;

      while ((data_end != d_itr) && (zero_or_more != (*p_itr)))
      {
         if (((*p_itr) != (*d_itr)) && (zero_or_one != (*p_itr)))
         {
            return false;
         }
         ++p_itr;
         ++d_itr;
      }

      while (data_end != d_itr)
      {
         if (zero_or_more == (*p_itr))
         {
            if (pattern_end == (++p_itr))
            {
               return true;
            }
            m_itr = p_itr;
            c_itr = d_itr;
            ++c_itr;
         }
         else if (((*p_itr) == (*d_itr)) || (zero_or_one == (*p_itr)))
         {
            ++p_itr;
            ++d_itr;
         }
         else
         {
            p_itr = m_itr;
            d_itr = c_itr++;
         }
      }

      while ((p_itr != pattern_end) && (zero_or_more == (*p_itr))) ++p_itr;

      return (p_itr == pattern_end);
   }

   inline bool match(const std::string& wild_card,
                     const std::string& str)
   {
      /*
         * : Zero or more match
         ? : Zero or one match
      */
      return match(wild_card.data(),
                   wild_card.data() + wild_card.size(),
                   str.data(),
                   str.data() + str.size(),
                   '*',
                   '?');
   }

   namespace tokenize_options
   {
      typedef std::size_t type;
      enum
      {
         default_mode            = 0,
         compress_delimiters     = 1,
         include_1st_delimiter   = 2,
         include_all_delimiters  = 4
      };

      static inline bool perform_compress_delimiters(const type& split_opt)
      {
         return compress_delimiters == (split_opt & compress_delimiters);
      }

      static inline bool perform_include_1st_delimiter(const type& split_opt)
      {
         return include_1st_delimiter == (split_opt & include_1st_delimiter);
      }

      static inline bool perform_include_all_delimiters(const type& split_opt)
      {
         return include_all_delimiters == (split_opt & include_all_delimiters);
      }

   } // namespace tokenize_options

   template <typename Iterator, typename DelimiterPredicate>
   class tokenizer
   {
   private:

      template <typename Iterartor,
                typename Predicate,
                typename T = std::pair<Iterator,Iterator> >
      class tokenizer_iterator : public std::iterator<std::forward_iterator_tag,T>
      {
      protected:

         typedef Iterator iterator;
         typedef const iterator const_iterator;
         typedef typename std::pair<iterator,iterator> range_type;

      public:

         explicit inline tokenizer_iterator(const iterator begin,
                                            const iterator end,
                                            const Predicate& predicate,
                                            const tokenize_options::type tokenize_option = tokenize_options::default_mode)
         : predicate_(predicate),
           end_(end),
           range_(begin,begin),
           current_token_(end,end),
           compress_delimiters_(tokenize_options::perform_compress_delimiters(tokenize_option)),
           include_1st_delimiter_(tokenize_options::perform_include_1st_delimiter(tokenize_option)),
           include_all_delimiters_(tokenize_options::perform_include_all_delimiters(tokenize_option)),
           include_delimiters_(include_1st_delimiter_ || include_all_delimiters_),
           last_token_done_(false)
         {
            if (end != begin)
            {
               this->operator++();
            }
         }

         inline tokenizer_iterator& operator++()
         {
            if (last_token_done_)
            {
               range_.first = range_.second;
               return (*this);
            }
            else if (end_ != range_.second)
            {
               range_.first = range_.second;
            }

            while (end_ != range_.second)
            {
              if (predicate_(*(range_.second)))
              {
                 if (include_delimiters_)
                 {
                    if (include_1st_delimiter_)
                       ++range_.second;
                    else if (include_all_delimiters_)
                       while ((end_ != range_.second) && predicate_(*(range_.second))) ++range_.second;
                    current_token_ = range_;
                    if ((!include_all_delimiters_) && compress_delimiters_)
                       while ((end_ != range_.second) && predicate_(*(range_.second))) ++range_.second;
                 }
                 else
                 {
                    current_token_ = range_;
                    if (compress_delimiters_)
                       while ((end_ != (++range_.second)) && predicate_(*(range_.second))) ;
                    else
                       ++range_.second;
                 }
                 return (*this);
              }
              else
                 ++range_.second;
            }

            if (range_.first != range_.second)
            {
               current_token_.second = range_.second;
               if (!last_token_done_)
               {
                  if (predicate_(*(range_.second - 1)))
                     current_token_.first = range_.second;
                  else
                     current_token_.first = range_.first;
                  last_token_done_ = true;
               }
               else
                  range_.first = range_.second;
            }

            return (*this);
         }

         inline tokenizer_iterator operator++(int)
         {
            tokenizer_iterator tmp = (*this);
            this->operator++();
            return tmp;
         }

         inline tokenizer_iterator& operator+=(const int inc)
         {
            if (inc > 0)
            {
               for (int i = 0; i < inc; ++i, ++(*this)) ;
            }
            return (*this);
         }

         inline T operator*() const
         {
            return current_token_;
         }

         inline std::string as_string() const
         {
            return std::string(current_token_.first,current_token_.second);
         }

         inline bool operator==(const tokenizer_iterator& itr) const
         {
            return (range_ == itr.range_) && (end_ == itr.end_);
         }

         inline bool operator!=(const tokenizer_iterator& itr) const
         {
            return (range_ != itr.range_) || (end_ != itr.end_);
         }

         inline tokenizer_iterator& operator=(const tokenizer_iterator& itr)
         {
            if (this != &itr)
            {
               range_                  = itr.range_;
               current_token_          = itr.current_token_;
               end_                    = itr.end_;
               compress_delimiters_    = itr.compress_delimiters_;
               include_1st_delimiter_  = itr.include_1st_delimiter_;
               include_all_delimiters_ = itr.include_all_delimiters_;
               include_delimiters_     = itr.include_delimiters_;
               last_token_done_        = itr.last_token_done_;
            }
            return (*this);
         }

         inline std::string remaining() const
         {
            return std::string(current_token_.first,end_);
         }

      protected:

         const Predicate& predicate_;
         iterator end_;
         range_type range_;
         range_type current_token_;
         bool compress_delimiters_;
         bool include_1st_delimiter_;
         bool include_all_delimiters_;
         bool include_delimiters_;
         bool last_token_done_;
      };

   public:

      typedef typename std::iterator_traits<Iterator>::value_type value_type;
      typedef DelimiterPredicate predicate;
      typedef tokenizer_iterator<Iterator,DelimiterPredicate> iterator;
      typedef const iterator const_iterator;
      typedef iterator& iterator_ref;
      typedef const_iterator& const_iterator_ref;

      inline tokenizer(const Iterator begin,
                       const Iterator end,
                       const DelimiterPredicate& predicate,
                       const tokenize_options::type tokenize_options = tokenize_options::default_mode)
      : tokenize_options_(tokenize_options),
        predicate_(predicate),
        begin_(begin),
        end_(end),
        begin_itr_(begin_,end_,predicate_,tokenize_options_),
        end_itr_(end_,end_,predicate_,tokenize_options_)
      {}

      inline tokenizer(const std::string& s,
                       const DelimiterPredicate& predicate,
                       const tokenize_options::type tokenize_options = tokenize_options::default_mode)
      : tokenize_options_(tokenize_options),
        predicate_(predicate),
        begin_(s.data()),
        end_(s.data() + s.size()),
        begin_itr_(begin_,end_,predicate_,tokenize_options_),
        end_itr_(end_,end_,predicate_,tokenize_options_)
      {}

      inline tokenizer& operator=(const tokenizer& t)
      {
         if (this != &t)
         {
            begin_            = t.begin_;
            end_              = t.end_;
            end_itr_          = t.end_itr_;
            begin_itr_        = t.begin_itr_;
            tokenize_options_ = t.tokenize_options_;
         }
         return (*this);
      }

      inline void assign(const std::string& s) const
      {
         assign(s.data(),s.data() + s.size());
      }

      inline void assign(const std::string& s)
      {
         assign(s.data(),s.data() + s.size());
      }

      inline void assign(const Iterator begin, const Iterator end)
      {
        begin_ = begin;
        end_ = end;
        begin_itr_ = iterator(begin_,end_,predicate_,tokenize_options_);
        end_itr_ = iterator(end_,end_,predicate_,tokenize_options_);
      }

      inline const_iterator_ref begin() const
      {
         return begin_itr_;
      }

      inline const_iterator_ref end() const
      {
         return end_itr_;
      }

   private:

      tokenize_options::type tokenize_options_;
      const DelimiterPredicate& predicate_;
      Iterator begin_;
      Iterator end_;
      iterator begin_itr_;
      iterator end_itr_;
   };

   namespace std_string
   {
      template <typename DelimiterPredicate = single_delimiter_predicate<std::string::value_type> >
      struct tokenizer
      {
         typedef DelimiterPredicate predicate_type;
         typedef const std::string::value_type* string_iterator_type;
         typedef strtk::tokenizer<string_iterator_type,DelimiterPredicate> type;
         typedef strtk::tokenizer<string_iterator_type,multiple_char_delimiter_predicate> md_type;
         typedef std::pair<string_iterator_type,string_iterator_type> iterator_type;
      };

   } // namespace std_string

   template <typename Sequence>
   class back_inserter_with_valuetype_iterator : public std::iterator<std::output_iterator_tag,
                                                                      typename Sequence::value_type,
                                                                      void,
                                                                      void,
                                                                      void>
   {
   public:

      explicit inline back_inserter_with_valuetype_iterator(Sequence& sequence)
      : sequence_(sequence)
      {}

      back_inserter_with_valuetype_iterator(const back_inserter_with_valuetype_iterator& it)
      : sequence_(it.sequence_)
      {}

      inline back_inserter_with_valuetype_iterator& operator=(const back_inserter_with_valuetype_iterator& it)
      {
         if (this != &it)
         {
            this->sequence_ = it.sequence_;
         }
         return (*this);
      }

      inline back_inserter_with_valuetype_iterator& operator=(const typename Sequence::value_type& v)
      {
         sequence_.push_back(v);
         return (*this);
      }

      inline void operator()(const typename Sequence::value_type& v)
      {
         sequence_.push_back(v);
      }

      inline back_inserter_with_valuetype_iterator& operator*()
      {
         return (*this);
      }

      inline back_inserter_with_valuetype_iterator& operator++()
      {
         return (*this);
      }

      inline back_inserter_with_valuetype_iterator operator++(int)
      {
         return (*this);
      }

   private:

      Sequence& sequence_;
   };

   template <typename Sequence>
   inline back_inserter_with_valuetype_iterator<Sequence> back_inserter_with_valuetype(Sequence& sequence_)
   {
      return (back_inserter_with_valuetype_iterator<Sequence>(sequence_));
   }

   template <typename Set>
   class inserter_with_valuetype_iterator : public std::iterator<std::output_iterator_tag,
                                                                 typename Set::value_type,
                                                                 void,
                                                                 void,
                                                                 void>
   {
   public:

      explicit inline inserter_with_valuetype_iterator(Set& set)
      : set_(set)
      {}

      inserter_with_valuetype_iterator(const inserter_with_valuetype_iterator& itr)
      : set_(itr.set_)
      {}

      inline inserter_with_valuetype_iterator& operator=(const inserter_with_valuetype_iterator& itr)
      {
         if (this != &itr)
         {
            this->set_ = itr.set_;
         }
         return (*this);
      }

      inline inserter_with_valuetype_iterator& operator=(const typename Set::value_type& v)
      {
         set_.insert(v);
         return (*this);
      }

      inline void operator()(const typename Set::value_type& v)
      {
         set_.insert(v);
      }

      inline inserter_with_valuetype_iterator& operator*()
      {
         return (*this);
      }

      inline inserter_with_valuetype_iterator& operator++()
      {
         return (*this);
      }

      inline inserter_with_valuetype_iterator operator++(int)
      {
         return (*this);
      }

   private:

      Set& set_;
   };

   template <typename Set>
   inline inserter_with_valuetype_iterator<Set> inserter_with_valuetype(Set& set_)
   {
      return (inserter_with_valuetype_iterator<Set>(set_));
   }

   template <typename Container>
   class push_inserter_iterator : public std::iterator<std::output_iterator_tag,
                                                       void,
                                                       void,
                                                       void,
                                                       void>
   {
   public:

      explicit inline push_inserter_iterator(Container& container)
      : container_(container)
      {}

      inline push_inserter_iterator& operator=(const push_inserter_iterator& itr)
      {
         if (this != &itr)
         {
            this->container_ = itr.container_;
         }
         return (*this);
      }

      inline push_inserter_iterator<Container>& operator=(typename Container::const_reference v)
      {
         container_.push(v);
         return (*this);
      }

      inline push_inserter_iterator<Container>& operator*()
      {
         return (*this);
      }

      inline push_inserter_iterator<Container>& operator++()
      {
         return (*this);
      }

      inline push_inserter_iterator<Container> operator++(int)
      {
         return (*this);
      }

   private:

      Container& container_;
   };

   template <typename Container>
   inline push_inserter_iterator<Container> push_inserter(Container& c)
   {
      return push_inserter_iterator<Container>(c);
   }

   template <typename Function>
   class functional_inserter_iterator : public std::iterator<std::output_iterator_tag,
                                                             void,
                                                             void,
                                                             void,
                                                             void>
   {
   public:

      explicit inline functional_inserter_iterator(Function function)
      : function_(function)
      {}

      functional_inserter_iterator(const functional_inserter_iterator& it)
      : function_(it.function_)
      {}

      inline functional_inserter_iterator& operator=(const functional_inserter_iterator& it)
      {
         if (this != &it)
         {
            this->function_ = it.function_;
         }
         return (*this);
      }

      template <typename T>
      inline functional_inserter_iterator& operator=(const T& t)
      {
         function_(t);
         return (*this);
      }

      template <typename T>
      inline void operator()(const T& t)
      {
         function_(t);
      }

      inline functional_inserter_iterator& operator*()
      {
         return (*this);
      }

      inline functional_inserter_iterator& operator++()
      {
         return (*this);
      }

      inline functional_inserter_iterator operator++(int)
      {
         return (*this);
      }

   private:

      Function function_;
   };

   template <typename Function>
   inline functional_inserter_iterator<Function> functional_inserter(Function function)
   {
      return (functional_inserter_iterator<Function>(function));
   }

   namespace split_options
   {
      typedef std::size_t type;
      enum
      {
         default_mode            = 0,
         compress_delimiters     = 1,
         include_1st_delimiter   = 2,
         include_all_delimiters  = 4
      };

      static inline bool perform_compress_delimiters(const type& split_opt)
      {
         return compress_delimiters == (split_opt & compress_delimiters);
      }

      static inline bool perform_include_1st_delimiter(const type& split_opt)
      {
         return include_1st_delimiter == (split_opt & include_1st_delimiter);
      }

      static inline bool perform_include_all_delimiters(const type& split_opt)
      {
         return include_all_delimiters == (split_opt & include_all_delimiters);
      }

   } // namespace split_options

   template <typename DelimiterPredicate,
             typename Iterator,
             typename OutputIterator>
   inline std::size_t split(const DelimiterPredicate& delimiter,
                            const Iterator begin,
                            const Iterator end,
                            OutputIterator out,
                            const split_options::type split_option = split_options::default_mode)
   {
      if (begin == end) return 0;
      std::size_t token_count = 0;
      std::pair<Iterator,Iterator> range(begin,begin);
      const bool compress_delimiters = split_options::perform_compress_delimiters(split_option);
      const bool include_1st_delimiter = split_options::perform_include_1st_delimiter(split_option);
      const bool include_all_delimiters = (!include_1st_delimiter) && split_options::perform_include_all_delimiters(split_option);
      const bool include_delimiters = include_1st_delimiter || include_all_delimiters;

      while (end != range.second)
      {
         if (delimiter(*range.second))
         {
            if (include_delimiters)
            {
               if (include_1st_delimiter)
                  ++range.second;
               else if (include_all_delimiters)
                  while ((end != range.second) && delimiter(*range.second)) ++range.second;
               (*out) = range;
               ++out;
               if ((!include_all_delimiters) && compress_delimiters)
                  while ((end != range.second) && delimiter(*range.second)) ++range.second;
            }
            else
            {
               (*out) = range;
               ++out;
               if (compress_delimiters)
                  while ((end != (++range.second)) && delimiter(*range.second)) ;
               else
                  ++range.second;
            }
            ++token_count;
            range.first = range.second;
         }
         else
            ++range.second;
      }

      if ((range.first != range.second) || delimiter(*(range.second - 1)))
      {
         (*out) = range;
         ++out;
         ++token_count;
      }

      return token_count;
   }

   template <typename DelimiterPredicate,
             typename Iterator,
             typename OutputIterator>
   inline std::size_t split(const DelimiterPredicate& delimiter,
                            const std::pair<Iterator,Iterator>& range,
                            OutputIterator out,
                            const split_options::type split_option = split_options::default_mode)
   {
      return split(delimiter,
                   range.first,range.second,
                   out,
                   split_option);
   }

   template <typename DelimiterPredicate,
             typename Iterator,
             typename OutputIterator>
   inline std::size_t split(const char* delimiters,
                            const std::pair<Iterator,Iterator>& range,
                            OutputIterator out,
                            const split_options::type split_option = split_options::default_mode)
   {
      if (1 == details::strnlength(delimiters,256))
         return split(single_delimiter_predicate<std::string::value_type>(delimiters[0]),
                      range.first,range.second,
                      out,
                      split_option);
      else
         return split(multiple_char_delimiter_predicate(delimiters),
                      range.first,range.second,
                      out,
                      split_option);
   }

   template <typename DelimiterPredicate,
             typename Iterator,
             typename OutputIterator>
   inline std::size_t split(const std::string& delimiters,
                            const std::pair<Iterator,Iterator>& range,
                            OutputIterator out,
                            const split_options::type split_option = split_options::default_mode)
   {
      if (1 == delimiters.size())
         return split(single_delimiter_predicate<std::string::value_type>(delimiters[0]),
                      range.first,range.second,
                      out,
                      split_option);
      else
         return split(multiple_char_delimiter_predicate(delimiters),
                      range.first,range.second,
                      out,
                      split_option);
   }

   template <typename OutputIterator>
   inline std::size_t split(const char* delimiters,
                            const std::string& str,
                            OutputIterator out,
                            const split_options::type& split_option = split_options::default_mode)
   {
      if (1 == details::strnlength(delimiters,256))
         return split(single_delimiter_predicate<std::string::value_type>(delimiters[0]),
                      str.data(), str.data() + str.size(),
                      out,
                      split_option);
      else
         return split(multiple_char_delimiter_predicate(delimiters),
                      str.data(), str.data() + str.size(),
                      out,
                      split_option);
   }

   template <typename OutputIterator>
   inline std::size_t split(const std::string& delimiters,
                            const std::string& str,
                            OutputIterator out,
                            const split_options::type& split_option = split_options::default_mode)
   {
      if (1 == delimiters.size())
         return split(single_delimiter_predicate<std::string::value_type>(delimiters[0]),
                      str.data(), str.data() + str.size(),
                      out,
                      split_option);
      else
         return split(multiple_char_delimiter_predicate(delimiters),
                      str.data(), str.data() + str.size(),
                      out,
                      split_option);
   }

   template <typename OutputIterator>
   inline std::size_t split(const std::string::value_type delimiter,
                            const std::string& str,
                            OutputIterator out,
                            const split_options::type& split_option = split_options::default_mode)
   {
      return split(single_delimiter_predicate<std::string::value_type>(delimiter),
                   str.data(), str.data() + str.size(),
                   out,
                   split_option);
   }

   template <typename Allocator,
             template <typename,typename> class Sequence>
   inline std::size_t split(const char* delimiters,
                            const std::string& str,
                            Sequence<std::pair<const char*, const char*>,Allocator>& sequence,
                            const split_options::type& split_option = split_options::default_mode)
   {
      if (1 == details::strnlength(delimiters,256))
         return split(single_delimiter_predicate<std::string::value_type>(delimiters[0]),
                      str.data(), str.data() + str.size(),
                      std::back_inserter(sequence),
                      split_option);
      else
         return split(multiple_char_delimiter_predicate(delimiters),
                      str.data(), str.data() + str.size(),
                      std::back_inserter(sequence),
                      split_option);
   }

   template <typename Allocator,
             template <typename,typename> class Sequence>
   inline std::size_t split(const std::string& delimiters,
                            const std::string& str,
                            Sequence<std::pair<const char*, const char*>,Allocator>& sequence,
                            const split_options::type& split_option = split_options::default_mode)
   {
      if (1 == delimiters.size())
         return split(single_delimiter_predicate<std::string::value_type>(delimiters[0]),
                      str.data(), str.data() + str.size(),
                      std::back_inserter(sequence),
                      split_option);
      else
         return split(multiple_char_delimiter_predicate(delimiters),
                      str.data(), str.data() + str.size(),
                      std::back_inserter(sequence),
                      split_option);
   }

   template <typename DelimiterPredicate,
             typename OutputIterator>
   inline std::size_t split(const DelimiterPredicate& delimiter,
                            const std::string& str,
                            OutputIterator out,
                            const split_options::type& split_option = split_options::default_mode)
   {
      return split(delimiter,
                   str.data(), str.data() + str.size(),
                   out,
                   split_option);
   }

   class token_grid
   {
   public:

      typedef const unsigned char* iterator_t;
      typedef unsigned int index_t;
      typedef std::pair<iterator_t,iterator_t> range_t;
      typedef std::deque<range_t> token_list_t;
      typedef std::pair<index_t,index_t> row_index_range_t;
      typedef std::deque<row_index_range_t> row_index_t;
      typedef std::pair<index_t,index_t> row_range_t;
      typedef std::pair<index_t,index_t> col_range_t;

   private:

      struct store
      {
         token_list_t token_list;
         row_index_t   row_index;
         std::size_t  max_column;

         inline void clear()
         {
            token_list.clear();
            row_index.clear();
         }

         inline range_t operator()(const std::size_t& col, const std::size_t& row) const
         {
            if (row < row_index.size())
            {
               const row_index_range_t& r = row_index[row];
               if (col < (r.second - r.first + 1))
                  return *(token_list.begin() + (r.first + col));
               else
                  return null_range();
            }
            else
               return null_range();
         }

         inline std::size_t token_count(const row_index_range_t& r) const
         {
            return (r.second - r.first + 1);
         }

         inline std::size_t token_count(const std::size_t& index) const
         {
            return token_count(row_index[index]);
         }

         inline static range_t null_range()
         {
            static const range_t null_range_ = range_t(reinterpret_cast<const unsigned char*>(0),
                                                       reinterpret_cast<const unsigned char*>(0));
            return null_range_;
         }

      };

      template <typename DelimiterPredicate = multiple_char_delimiter_predicate>
      struct row_processor
      {
         row_processor(store& idx,
                       DelimiterPredicate& tp,
                       const split_options::type split_mode = split_options::compress_delimiters)
         : idx_(idx),
           row_start_index_(0),
           row_end_index_(0),
           token_predicate_(tp),
           split_mode_(split_mode)
         {
            idx_.max_column = std::numeric_limits<std::size_t>::min();
         }

         inline void operator()(const range_t& range)
         {
            if (0 == std::distance(range.first,range.second))
               return;
            row_start_index_ = idx_.token_list.size();
            std::size_t token_count = split(token_predicate_,
                                            range.first,range.second,
                                            std::back_inserter(idx_.token_list),
                                            split_mode_);
            row_end_index_ = row_start_index_ + token_count - 1;
            idx_.row_index.push_back(std::make_pair(row_start_index_,row_end_index_));
            if (token_count > idx_.max_column)
               idx_.max_column = token_count;
         }

         row_processor<DelimiterPredicate> operator=(const row_processor<DelimiterPredicate>&);

         store& idx_;
         std::size_t row_start_index_;
         std::size_t row_end_index_;
         DelimiterPredicate& token_predicate_;
         split_options::type split_mode_;
      };

   public:

      inline row_range_t range(std::size_t lower_bound,
                                  std::size_t upper_bound = std::numeric_limits<std::size_t>::max()) const
      {
         if (upper_bound == std::numeric_limits<std::size_t>::max())
         {
            upper_bound = dsv_index_.token_list.size();
         }
         else if (upper_bound > dsv_index_.token_list.size())
         {
            return row_range_t(std::numeric_limits<std::size_t>::max(),std::numeric_limits<std::size_t>::max());
         }
         else if (lower_bound > upper_bound)
         {
            return row_range_t(std::numeric_limits<std::size_t>::max(),std::numeric_limits<std::size_t>::max());
         }
         return row_range_t(lower_bound,upper_bound);
      }

      struct options
      {
         options()
         : row_split_option(split_options::compress_delimiters),
           column_split_option(split_options::compress_delimiters),
           row_delimiters("\n\r"),
           column_delimiters(",|;\t "),
           support_dquotes(false)
         {}

         options(split_options::type sro,
                 split_options::type sco,
                 const std::string& rd,
                 const std::string& cd,
                 const bool support_dq = false)
         : row_split_option(sro),
           column_split_option(sco),
           row_delimiters(rd),
           column_delimiters(cd),
           support_dquotes(support_dq)
         {}

         split_options::type row_split_option;
         split_options::type column_split_option;
         std::string row_delimiters;
         std::string column_delimiters;
         bool support_dquotes;
      };

      class row_type
      {
      private:

         typedef std::pair<bool,row_type*> row_pair_type;

      public:

         row_type()
         : index_(std::numeric_limits<std::size_t>::max())
         {}

         row_type(const std::size_t& index,
                  const store& dsv_index)
         : index_(index),
           size_ (dsv_index.token_count(index)),
           begin_(dsv_index.token_list.begin() +  dsv_index.row_index[index].first)
         {}

         template <typename T>
         inline T operator[](const std::size_t& index) const
         {
            const range_t& range = *(begin_ + index);
            return string_to_type_converter<T>(range.first,range.second);
         }

         template <typename T>
         inline T get(const std::size_t& index) const
         {
            return row_type::operator[]<T>(index);
         }

         inline col_range_t all_columns() const
         {
            return col_range_t(0,static_cast<index_t>(size()));
         }

         inline range_t range() const
         {
            return range_t((*begin_).first,(*(begin_ + (size_ - 1))).second);
         }

         inline range_t token(const std::size_t& index) const
         {
            return *(begin_ + index);
         }

         inline std::size_t index() const
         {
            return index_;
         }

         inline std::size_t size() const
         {
            return size_;
         }

         bool validate_column_range(const col_range_t& range) const
         {
            if ((range.first > size()) || (range.second > size()))
               return false;
            else if (range.first > range.second)
               return false;
            else
               return true;
         }

         col_range_t range(const std::size_t& lower_bound,
                           const std::size_t& upper_bound = std::numeric_limits<std::size_t>::max()) const
         {
            if (std::numeric_limits<std::size_t>::max() != upper_bound)
               return col_range_t(lower_bound,upper_bound);
            else
              return col_range_t(lower_bound,static_cast<index_t>(size()));
         }

      private:

         template <typename T>
         inline bool process(const range_t& range, T& t) const
         {
            return string_to_type_converter(range.first,range.second,t);
         }

      private:

         std::size_t index_;
         std::size_t size_;
         token_list_t::const_iterator begin_;
      };

      token_grid()
      : file_name_(""),
        buffer_(0),
        buffer_size_(0),
        min_column_count_(0),
        max_column_count_(0),
        load_from_file_(false),
        state_(false)
      {}

      token_grid(const char* input_buffer,
                 const std::size_t& input_buffer_size,
                 const token_grid::options& options)
      : file_name_(""),
        buffer_(reinterpret_cast<unsigned char*>(const_cast<char*>(input_buffer))),
        buffer_size_(input_buffer_size),
        min_column_count_(0),
        max_column_count_(0),
        options_(options),
        load_from_file_(false),
        state_(load())
      {}

     ~token_grid()
      {
         if ((load_from_file_) && (0 != buffer_))
         {
            delete [] buffer_;
            buffer_ = 0;
         }
      }

      inline bool operator!() const
      {
         return !state_;
      }

      inline std::string source_file() const
      {
         return file_name_;
      }

      inline std::size_t row_count() const
      {
         return dsv_index_.row_index.size();
      }

      inline std::size_t min_column_count() const
      {
         return min_column_count_;
      }

      inline std::size_t max_column_count() const
      {
         return max_column_count_;
      }

      inline range_t token(const unsigned int& row, const std::size_t& col) const
      {
         return dsv_index_(col,row);
      }

      template <typename T>
      inline T get(const unsigned int& row, const std::size_t& col)
      {
         range_t r = token(row,col);
         return string_to_type_converter<T>(r.first,r.second);
      }

      inline row_type row(const unsigned int& row_index) const
      {
         return row_type(row_index,dsv_index_);
      }

      /*inline row_range_t all_rows() const
      {
         return row_range_t(0,static_cast<index_t>(dsv_index_.row_index.size()));
      }

      inline void remove_row(const std::size_t& index)
      {
         if (index < dsv_index_.row_index.size())
         {
            dsv_index_.remove_row(index);
         }
      }*/

      inline void clear(const bool force_delete_buffer = false)
      {
         if (load_from_file_ || force_delete_buffer)
            delete[] buffer_;
         buffer_ = 0;
         buffer_size_ = 0;
         dsv_index_.clear();
         min_column_count_ = 0;
         max_column_count_ = 0;
         state_ = false;
         file_name_ = "";
      }

   private:

      token_grid(const token_grid& tg);
      token_grid& operator=(const token_grid& tg);

      class double_quotes_predicate
      {
      public:

         double_quotes_predicate(const std::string& delimiters)
         : in_bracket_range_(false),
           mdp_(delimiters)
         {}

         inline bool operator()(const unsigned char c) const
         {
            if ('"' == c)
            {
               in_bracket_range_ = !in_bracket_range_;
               return true;
            }
            else if (in_bracket_range_)
               return false;
            else
               return mdp_(c);
         }

         inline void reset()
         {
            in_bracket_range_ = false;
         }

      private:

         mutable bool in_bracket_range_;
         mutable strtk::multiple_char_delimiter_predicate mdp_;
      };

      inline bool load()
      {
         if (load_from_file_)
            return false;

         dsv_index_.token_list.clear();
         dsv_index_.row_index.clear();

         multiple_char_delimiter_predicate text_newline_predicate(options_.row_delimiters);

         if (!options_.support_dquotes)
         {
            multiple_char_delimiter_predicate token_predicate(options_.column_delimiters);
            strtk::split(text_newline_predicate,
                         buffer_, buffer_ + buffer_size_,
                         strtk::functional_inserter(
                            row_processor<multiple_char_delimiter_predicate>(dsv_index_,token_predicate,options_.column_split_option)),
                         strtk::split_options::compress_delimiters);
         }
         else
         {
            double_quotes_predicate token_predicate_dblq(options_.column_delimiters);
            strtk::split(text_newline_predicate,
                         buffer_, buffer_ + buffer_size_,
                         strtk::functional_inserter(
                            row_processor<double_quotes_predicate>(dsv_index_,token_predicate_dblq,options_.column_split_option)),
                        strtk::split_options::compress_delimiters);
         }
         update_minmax_columns();
         return true;
      }

      inline void update_minmax_columns()
      {
         min_column_count_ = std::numeric_limits<std::size_t>::max();
         max_column_count_ = std::numeric_limits<std::size_t>::min();
         for (std::size_t i = 0; i < dsv_index_.row_index.size(); ++i)
         {
            const row_index_range_t& r = dsv_index_.row_index[i];
            const std::size_t number_of_tokens = dsv_index_.token_count(r);
            if (number_of_tokens > max_column_count_)
               max_column_count_ = number_of_tokens;
            if (number_of_tokens < min_column_count_)
               min_column_count_ = number_of_tokens;
         }
      }

   private:

      store dsv_index_;
      std::string file_name_;
      unsigned char* buffer_;
      std::size_t buffer_size_;
      std::size_t min_column_count_;
      std::size_t max_column_count_;
      options options_;
      bool load_from_file_;
      bool state_;
   };

   // Required for broken versions of GCC pre 4.5
   namespace util { class value; }

   namespace details
   {

      class conv_to_lcase_impl
      {
      public:

         conv_to_lcase_impl(std::string& s)
         : s_(&s)
         {}

         template <typename InputIterator>
         inline bool operator()(InputIterator begin, InputIterator end)
         {
            std::string& s = (*s_);
            s.assign(begin,end);
            convert_to_lowercase(s);
            return true;
         }

         inline conv_to_lcase_impl& ref()
         {
            return (*this);
         }

      private:

         std::string* s_;
      };

      class conv_to_ucase_impl
      {
      public:

         conv_to_ucase_impl(std::string& s)
         : s_(&s)
         {}

         template <typename InputIterator>
         inline bool operator()(InputIterator begin, InputIterator end)
         {
            std::string& s = (*s_);
            s.assign(begin,end);
            convert_to_uppercase(s);
            return true;
         }

         inline conv_to_ucase_impl& ref()
         {
            return (*this);
         }

      private:

         std::string* s_;
      };

      class fill_array_impl
      {
      public:

         fill_array_impl(unsigned char* data, const std::size_t& size)
         : data_(data),
           size_(size)
         {}

         template <typename InputIterator>
         inline bool operator()(InputIterator begin, InputIterator end)
         {
            const std::size_t range_size = static_cast<std::size_t>(std::distance(begin,end));
            if (range_size != size_)
               return false;
            std::memcpy(data_,begin,range_size);
            return true;
         }

         inline fill_array_impl& ref()
         {
            return (*this);
         }

         inline fill_array_impl& set(unsigned char* data, const std::size_t& size)
         {
            data_ = data;
            size_ = size;
            return (*this);
         }

         inline fill_array_impl& set(char* data, const std::size_t& size)
         {
            data_ = reinterpret_cast<unsigned char*>(data);
            size_ = size;
            return (*this);
         }

         inline fill_array_impl& set_data(unsigned char* data)
         {
            data_ = data;
            return (*this);
         }

         inline fill_array_impl& set_data(char* data)
         {
            data_ = reinterpret_cast<unsigned char*>(data);
            return (*this);
         }

         inline fill_array_impl& set_size(const std::size_t& size)
         {
            size_ = size;
            return (*this);
         }

      private:

         unsigned char* data_;
         std::size_t size_;
      };

   }

   namespace details
   {
      template <typename>
      struct numeric { enum { length = 0, size = 32, bound_length = 0, min_exp = 0, max_exp = 0 }; };

      template<> struct numeric<short>                  { enum { length =  5, size = 16, bound_length =  4}; };
      template<> struct numeric<unsigned short>         { enum { length =  5, size = 16, bound_length =  4}; };

      template<> struct numeric<int>                    { enum { length = 10, size = 16, bound_length =  9}; };
      template<> struct numeric<unsigned int>           { enum { length = 10, size = 16, bound_length =  9}; };

      template<> struct numeric<long>                   { enum { length = 10, size = 16, bound_length =  9}; };
      template<> struct numeric<unsigned long>          { enum { length = 10, size = 16, bound_length =  9}; };

      template<> struct numeric<long long>              { enum { length = 19, size = 24, bound_length = 18}; };
      template<> struct numeric<unsigned long long int> { enum { length = 20, size = 24, bound_length = 19}; };

      template<> struct numeric<float>                  { enum { min_exp =  -38, max_exp =  +38, precision = 10}; };
      template<> struct numeric<double>                 { enum { min_exp = -308, max_exp = +308, precision = 15}; };
      template<> struct numeric<long double>            { enum { min_exp = -308, max_exp = +308, precision = 15}; };

      #define strtk_register_unsigned_type_tag(T)\
      template<> struct supported_conversion_to_type<T> { typedef unsigned_type_tag type; };\
      template<> struct supported_conversion_from_type<T> { typedef unsigned_type_tag type; };

      #define strtk_register_signed_type_tag(T)\
      template<> struct supported_conversion_to_type<T>{ typedef signed_type_tag type; };\
      template<> struct supported_conversion_from_type<T> { typedef signed_type_tag type; };

      #define strtk_register_real_type_tag(T)\
      template<> struct supported_conversion_to_type<T>{ typedef real_type_tag type; };

      #define strtk_register_byte_type_tag(T)\
      template<> struct supported_conversion_to_type<T>{ typedef byte_type_tag type; };\
      template<> struct supported_conversion_from_type<T> { typedef byte_type_tag type; };

      #define strtk_register_hex_number_type_tag(T)\
      template<> struct supported_conversion_to_type<T >{ typedef hex_number_type_tag type; };

      //template<> struct supported_conversion_to_type<hex_to_string_sink>{ typedef hex_string_type_tag type; };

      #define strtk_register_base64_type_tag(T)\
      template<> struct supported_conversion_to_type<T >{ typedef base64_type_tag type; };

      #define strtk_register_supported_iterator_type(T)\
      template<> struct supported_iterator_type<T> { enum { value = true }; };

      template<> struct supported_conversion_to_type<bool> { typedef bool_type_tag type; };
      template<> struct supported_iterator_type<bool> { enum { value = true }; };

      template<> struct supported_conversion_to_type<std::string> { typedef stdstring_type_tag type; };
      template<> struct supported_iterator_type<std::string> { enum { value = true }; };

      template<> struct supported_conversion_to_type<strtk::util::value> { typedef value_type_tag type; };
      template<> struct supported_conversion_from_type<strtk::util::value> { typedef value_type_tag type; };
      template<> struct supported_iterator_type<strtk::util::value> { enum { value = true }; };

      template<> struct supported_conversion_to_type<strtk::details::fill_array_impl> { typedef fillchararray_type_tag type; };
      template<> struct supported_iterator_type<strtk::details::fill_array_impl>      { enum { value = true }; };

      template<> struct supported_conversion_to_type<strtk::details::conv_to_lcase_impl> { typedef lcase_type_tag type; };
      template<> struct supported_iterator_type<strtk::details::conv_to_lcase_impl>      { enum { value = true }; };

      template<> struct supported_conversion_to_type<strtk::details::conv_to_ucase_impl> { typedef ucase_type_tag type; };
      template<> struct supported_iterator_type<strtk::details::conv_to_ucase_impl>      { enum { value = true }; };

      strtk_register_unsigned_type_tag(unsigned short)
      strtk_register_unsigned_type_tag(unsigned int)
      strtk_register_unsigned_type_tag(unsigned long)
      strtk_register_unsigned_type_tag(unsigned long long int)

      strtk_register_signed_type_tag(short)
      strtk_register_signed_type_tag(int)
      strtk_register_signed_type_tag(long)
      strtk_register_signed_type_tag(long long)

      strtk_register_real_type_tag(float)
      strtk_register_real_type_tag(double)
      strtk_register_real_type_tag(long double)

      strtk_register_byte_type_tag(unsigned char)
      strtk_register_byte_type_tag(signed char)
      strtk_register_byte_type_tag(char)

      strtk_register_supported_iterator_type(char*)
      strtk_register_supported_iterator_type(signed char*)
      strtk_register_supported_iterator_type(unsigned char*)
      strtk_register_supported_iterator_type(const char*)
      strtk_register_supported_iterator_type(const signed char*)
      strtk_register_supported_iterator_type(const unsigned char*)
      strtk_register_supported_iterator_type(std::string::iterator)
      strtk_register_supported_iterator_type(std::string::const_iterator)

      #undef strtk_register_unsigned_type_tag
      #undef strtk_register_signed_type_tag
      #undef strtk_register_real_type_tag
      #undef strtk_register_byte_type_tag
      #undef strtk_register_hex_number_type_tag
      #undef strtk_register_base64_type_tag
      #undef strtk_register_supported_iterator_type
      #undef strtk_register_stl_container_to_string_conv_type_tag
      #undef strtk_register_trim_type_tag

      template <typename Iterator>
      inline bool string_to_type_converter_impl(Iterator& begin, const Iterator end, strtk::util::value& v, value_type_tag)
      {
         return v(begin,end);
      }

      template <typename Iterator>
      inline bool string_to_type_converter_impl(Iterator& begin, const Iterator end, std::string& t, stdstring_type_tag)
      {
         t.assign(begin,end);
         begin = end;
         return true;
      }

      template <typename Iterator, typename Expect>
      inline bool string_to_type_converter_impl(Iterator& itr, const Iterator end, Expect& t, expect_type_tag)
      {
         if (!t(itr,end))
            return false;
         itr = end;
         return true;
      }

      template <typename Iterator, typename Like>
      inline bool string_to_type_converter_impl(Iterator& itr, const Iterator end, Like& t, like_type_tag)
      {
         if (!t(itr,end))
            return false;
         itr = end;
         return true;
      }

      template <typename Iterator, typename InRange>
      inline bool string_to_type_converter_impl(Iterator& itr, const Iterator end, InRange& t, inrange_type_tag)
      {
         if (!t(itr,end))
            return false;
         itr = end;
         return true;
      }

      template <typename Iterator, typename TrimToken>
      inline bool string_to_type_converter_impl(Iterator& itr, const Iterator end, TrimToken& t, trim_type_tag)
      {
         if (!t(itr,end))
            return false;
         itr = end;
         return true;
      }

      template <typename Iterator, typename CaseToken>
      inline bool string_to_type_converter_impl(Iterator& itr, const Iterator end, CaseToken& t, lcase_type_tag)
      {
         if (!t(itr,end))
            return false;
         itr = end;
         return true;
      }

      template <typename Iterator, typename CaseToken>
      inline bool string_to_type_converter_impl(Iterator& itr, const Iterator end, CaseToken& t, ucase_type_tag)
      {
         if (!t(itr,end))
            return false;
         itr = end;
         return true;
      }

      template <typename Iterator, typename Array>
      inline bool string_to_type_converter_impl(Iterator& itr, const Iterator end, Array& t, fillchararray_type_tag)
      {
         if (!t(itr,end))
            return false;
         itr = end;
         return true;
      }

      template <typename Iterator, typename T>
      inline bool string_to_type_converter_impl(Iterator& itr_external, const Iterator end, T& result, unsigned_type_tag)
      {
         if (end == itr_external) return false;

         Iterator itr = itr_external;

         if ('+' == (*itr))
            ++itr;

         if (end == itr)
            return false;

         while ((end != itr) && ('0' == (*itr))) ++itr;
         const std::size_t length = std::distance(itr,end);

         if (length > numeric<T>::length)
            return false;

         static const std::size_t bound_length = numeric<T>::bound_length;
         T t  = 0;

         if (0 != length)
         {
            std::size_t interim_length = std::min<std::size_t>(bound_length,length);
            const Iterator interim_end = itr + interim_length;
            unsigned int digit[8];
            T t0 = 0;
            T t1 = 0;
            T t2 = 0;
            T t3 = 0;

            //Needed for incompetent and broken msvc compiler versions
            #ifdef _MSC_VER
            #pragma warning(push)
            #pragma warning(disable: 4127)
            #endif

            while (interim_length > 7)
            {
               if (((digit[0] = (itr[0] - '0')) > 9) ||
                   ((digit[1] = (itr[1] - '0')) > 9) ||
                   ((digit[2] = (itr[2] - '0')) > 9) ||
                   ((digit[3] = (itr[3] - '0')) > 9) ||
                   ((digit[4] = (itr[4] - '0')) > 9) ||
                   ((digit[5] = (itr[5] - '0')) > 9) ||
                   ((digit[6] = (itr[6] - '0')) > 9) ||
                   ((digit[7] = (itr[7] - '0')) > 9))
                  return false;
               else
               {
                  t0 = static_cast<T>(digit[0] * 10000000 + digit[1] * 1000000);
                  t1 = static_cast<T>(digit[2] * 100000   + digit[3] *   10000);
                  t2 = static_cast<T>(digit[4] * 1000     + digit[5] *     100);
                  t3 = static_cast<T>(digit[6] * 10       + digit[7]          );
                  t  = t0 + t1 + t2 + t3 + static_cast<T>(t * 100000000);
                  itr += 8;
                  interim_length -= 8;
               }
            }

            while (interim_length > 3)
            {
               if (((digit[0] = (itr[0] - '0')) > 9) ||
                   ((digit[1] = (itr[1] - '0')) > 9) ||
                   ((digit[2] = (itr[2] - '0')) > 9) ||
                   ((digit[3] = (itr[3] - '0')) > 9))
                  return false;
               else
               {
                  t1 = static_cast<T>(digit[0] * 1000 + digit[1] * 100);
                  t2 = static_cast<T>(digit[2] * 10   + digit[3]      );
                  t3 = static_cast<T>(t * 10000                       );
                  t  = t1 + t2 + t3;
                  itr += 4;
                  interim_length -= 4;
               }
            }

            while (interim_length > 1)
            {
               if (((digit[0] = (itr[0] - '0')) > 9) ||
                   ((digit[1] = (itr[1] - '0')) > 9))
                  return false;
               else
               {
                  t1 = static_cast<T>(digit[0] * 10 + digit[1]);
                  t2 = static_cast<T>(t * 100                 );
                  t  = t1 + t2;
                  itr += 2;
                  interim_length -= 2;
               }
            }

            //Needed for incompetent and broken msvc compiler versions.
            #ifdef _MSC_VER
            #pragma warning(pop)
            #endif

            if (interim_length)
            {
               if ((digit[0] = (itr[0] - '0')) < 10)
               {
                  t = static_cast<T>(digit[0] + t * 10);
                  ++itr;
               }
               else
                  return false;
            }

            if (interim_end != end)
            {
               if (1 == std::distance(interim_end,end))
               {
                  typedef unsigned long long int num_type;
                  static const num_type max               = static_cast<num_type>(std::numeric_limits<T>::max());
                  static const num_type penultimate_bound = static_cast<num_type>(max / 10);
                  static const num_type final_digit       = static_cast<num_type>(max % 10);

                  digit[0] = static_cast<unsigned int>(*itr - '0');
                  if (digit[0] <= 9)
                  {
                     if (t > penultimate_bound)
                        return false;
                     else if ((penultimate_bound == t) && (final_digit < digit[0]))
                        return false;
                     t = static_cast<T>(digit[0] + t * 10);
                  }
                  else
                     return false;
               }
               else
                  return false;
            }
         }

         result = static_cast<T>(t);
         return true;
      }

      template <typename Iterator, typename T>
      inline bool string_to_type_converter_impl(Iterator& itr_external, const Iterator end, T& result, signed_type_tag)
      {
         if (end == itr_external) return false;

         Iterator itr = itr_external;

         bool negative = false;

         if ('+' == (*itr))
            ++itr;
         else if ('-' == (*itr))
         {
            ++itr;
            negative = true;
         }

         if (end == itr) return false;

         while ((end != itr) && ('0' == (*itr))) ++itr;

         const std::size_t length = std::distance(itr,end);

         if (length > numeric<T>::length)
            return false;

         static const std::size_t bound_length = numeric<T>::bound_length;
         T t  = 0;

         if (0 != length)
         {
            std::size_t interim_length = std::min<std::size_t>(bound_length,length);
            const Iterator interim_end = itr + interim_length;
            unsigned int digit[8];
            T t0 = 0;
            T t1 = 0;
            T t2 = 0;
            T t3 = 0;

            //Needed for incompetent and broken msvc compiler versions
            #ifdef _MSC_VER
            #pragma warning(push)
            #pragma warning(disable: 4127)
            #endif

            while (interim_length > 7)
            {
               if (((digit[0] = (itr[0] - '0')) > 9) ||
                   ((digit[1] = (itr[1] - '0')) > 9) ||
                   ((digit[2] = (itr[2] - '0')) > 9) ||
                   ((digit[3] = (itr[3] - '0')) > 9) ||
                   ((digit[4] = (itr[4] - '0')) > 9) ||
                   ((digit[5] = (itr[5] - '0')) > 9) ||
                   ((digit[6] = (itr[6] - '0')) > 9) ||
                   ((digit[7] = (itr[7] - '0')) > 9) )
                  return false;
               else
               {
                  t0 = static_cast<T>(digit[0] * 10000000 + digit[1] * 1000000);
                  t1 = static_cast<T>(digit[2] * 100000   + digit[3] *   10000);
                  t2 = static_cast<T>(digit[4] * 1000     + digit[5] *     100);
                  t3 = static_cast<T>(digit[6] * 10       + digit[7]          );
                  t  = t0 + t1 + t2 + t3 + static_cast<T>(t * 100000000);
                  itr += 8;
                  interim_length -= 8;
               }
            }

            while (interim_length > 3)
            {
               if (((digit[0] = (itr[0] - '0')) > 9) ||
                   ((digit[1] = (itr[1] - '0')) > 9) ||
                   ((digit[2] = (itr[2] - '0')) > 9) ||
                   ((digit[3] = (itr[3] - '0')) > 9) )
                  return false;
               else
               {
                  t0 = static_cast<T>(digit[0] * 1000 + digit[1] * 100);
                  t1 = static_cast<T>(digit[2] * 10   + digit[3]      );
                  t  = t0 + t1 + static_cast<T>(t * 10000);
                  itr += 4;
                  interim_length -= 4;
               }
            }

            while (interim_length > 2)
            {
               if (((digit[0] = (itr[0] - '0')) > 9) ||
                   ((digit[1] = (itr[1] - '0')) > 9) ||
                   ((digit[2] = (itr[2] - '0')) > 9))
                  return false;
               else
               {
                  t0 = static_cast<T>(digit[0] * 100 + digit[1] * 10);
                  t1 = static_cast<T>(t * 1000 + digit[2]           );
                  t  = t0 + t1;
                  itr += 3;
                  interim_length -= 3;
               }
            }

            while (interim_length > 1)
            {
               if (((digit[0] = (itr[0] - '0')) > 9) ||
                   ((digit[1] = (itr[1] - '0')) > 9))
                  return false;
               else
               {
                  t0 = static_cast<T>(digit[0] * 10 + digit[1]);
                  t  = t0 + static_cast<T>(t * 100);
                  itr += 2;
                  interim_length -= 2;
               }
            }

            //Needed for incompetent and broken msvc compiler versions.
            #ifdef _MSC_VER
            #pragma warning(pop)
            #endif

            if (interim_length)
            {
               if ((digit[0] = (itr[0] - '0')) < 10)
               {
                  t = static_cast<T>(digit[0] + t * 10);
                  ++itr;
               }
               else
                  return false;
            }

            if (interim_end != end)
            {
               if (1 == std::distance(interim_end,end))
               {
                  typedef unsigned long long int num_type;
                  static const num_type max = static_cast<num_type>(std::numeric_limits<T>::max());
                  static const num_type min = static_cast<num_type>(static_cast<long long>(-1) * std::numeric_limits<T>::min());
                  static const num_type positive_penultimate_bound = static_cast<num_type>(max / 10);
                  static const num_type negative_penultimate_bound = static_cast<num_type>(min / 10);
                  static const num_type positive_final_digit = static_cast<num_type>(max % 10);
                  static const num_type negative_final_digit = static_cast<num_type>(min % 10);

                  digit[0] = static_cast<unsigned int>(*itr - '0');

                  if (digit[0] < 10)
                  {
                     if (negative)
                     {
                        if (static_cast<num_type>(t) > negative_penultimate_bound)
                           return false;
                        else if (
                                 (negative_penultimate_bound == static_cast<num_type>(t)) &&
                                 (negative_final_digit < digit[0])
                                )
                           return false;
                     }
                     else
                     {
                        if (static_cast<num_type>(t) > positive_penultimate_bound)
                           return false;
                        else if (
                                 (positive_penultimate_bound == static_cast<num_type>(t)) &&
                                 (positive_final_digit < digit[0])
                                )
                           return false;
                     }
                     t = static_cast<T>(digit[0] + t * 10);
                  }
                  else
                     return false;
               }
               else
                  return false;
            }
         }
         itr_external = itr;
         result = static_cast<T>((negative) ? -t : t);
         return true;
      }
   } // namespace details
} // namespace strtk

#endif
