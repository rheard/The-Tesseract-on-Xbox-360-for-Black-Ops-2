#ifndef _DB_LOAD_H
#define _DB_LOAD_H

typedef void (__cdecl * Load_XAssetHeader_t)(bool atStreamStart);
extern Load_XAssetHeader_t Load_XAssetHeader;

#endif//_DB_LOAD_Hg