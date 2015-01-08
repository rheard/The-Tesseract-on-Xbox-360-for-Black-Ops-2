#ifndef _DB_REGISTRY
#define _DB_REGISTRY

#include "cg_main_mp.h"
#include "vector.h"
#include <stdio.h>

#include "cscr_stringlist.h"
#include "com_stringtable_obj.h"
#include "com_sessionmodes.h"
#include "physconstraints_load_obj.h"
#include "tracer_load_obj.h"
#include "bg_weapons_load_obj.h"
#include "bg_misctables.h"

enum XAssetType
{
  ASSET_TYPE_XMODELPIECES = 0x0,
  ASSET_TYPE_PHYSPRESET = 0x1,
  ASSET_TYPE_PHYSCONSTRAINTS = 0x2,
  ASSET_TYPE_DESTRUCTIBLEDEF = 0x3,
  ASSET_TYPE_XANIMPARTS = 0x4,
  ASSET_TYPE_XMODEL = 0x5,
  ASSET_TYPE_MATERIAL = 0x6,
  ASSET_TYPE_PIXELSHADER = 0x7,
  ASSET_TYPE_TECHNIQUE_SET = 0x8,
  ASSET_TYPE_IMAGE = 0x9,
  ASSET_TYPE_SOUND = 0xA,
  ASSET_TYPE_SOUND_PATCH = 0xB,
  ASSET_TYPE_CLIPMAP = 0xC,
  ASSET_TYPE_CLIPMAP_PVS = 0xD,
  ASSET_TYPE_COMWORLD = 0xE,
  ASSET_TYPE_GAMEWORLD_SP = 0xF,
  ASSET_TYPE_GAMEWORLD_MP = 0x10,
  ASSET_TYPE_MAP_ENTS = 0x11,
  ASSET_TYPE_GFXWORLD = 0x12,
  ASSET_TYPE_LIGHT_DEF = 0x13,
  ASSET_TYPE_UI_MAP = 0x14,
  ASSET_TYPE_FONT = 0x15,
  ASSET_TYPE_FONTICON = 0x16,
  ASSET_TYPE_MENULIST = 0x17,
  ASSET_TYPE_MENU = 0x18,
  ASSET_TYPE_LOCALIZE_ENTRY = 0x19,
  ASSET_TYPE_WEAPON = 0x1A,
  ASSET_TYPE_WEAPONDEF = 0x1B,
  ASSET_TYPE_WEAPON_VARIANT = 0x1C,
  ASSET_TYPE_WEAPON_FULL = 0x1D,
  ASSET_TYPE_ATTACHMENT = 0x1E,
  ASSET_TYPE_ATTACHMENT_UNIQUE = 0x1F,
  ASSET_TYPE_WEAPON_CAMO = 0x20,
  ASSET_TYPE_SNDDRIVER_GLOBALS = 0x21,
  ASSET_TYPE_FX = 0x22,
  ASSET_TYPE_IMPACT_FX = 0x23,
  ASSET_TYPE_AITYPE = 0x24,
  ASSET_TYPE_MPTYPE = 0x25,
  ASSET_TYPE_MPBODY = 0x26,
  ASSET_TYPE_MPHEAD = 0x27,
  ASSET_TYPE_CHARACTER = 0x28,
  ASSET_TYPE_XMODELALIAS = 0x29,
  ASSET_TYPE_RAWFILE = 0x2A,
  ASSET_TYPE_STRINGTABLE = 0x2B,
  ASSET_TYPE_LEADERBOARD = 0x2C,
  ASSET_TYPE_XGLOBALS = 0x2D,
  ASSET_TYPE_DDL = 0x2E,
  ASSET_TYPE_GLASSES = 0x2F,
  ASSET_TYPE_TEXTURELIST = 0x30,
  ASSET_TYPE_EMBLEMSET = 0x31,
  ASSET_TYPE_SCRIPTPARSETREE = 0x32,
  ASSET_TYPE_KEYVALUEPAIRS = 0x33,
  ASSET_TYPE_VEHICLEDEF = 0x34,
  ASSET_TYPE_MEMORYBLOCK = 0x35,
  ASSET_TYPE_ADDON_MAP_ENTS = 0x36,
  ASSET_TYPE_TRACER = 0x37,
  ASSET_TYPE_SKINNEDVERTS = 0x38,
  ASSET_TYPE_QDB = 0x39,
  ASSET_TYPE_SLUG = 0x3A,
  ASSET_TYPE_FOOTSTEP_TABLE = 0x3B,
  ASSET_TYPE_FOOTSTEPFX_TABLE = 0x3C,
  ASSET_TYPE_ZBARRIER = 0x3D,
  ASSET_TYPE_COUNT = 0x3E,
  ASSET_TYPE_STRING = 0x3E,
  ASSET_TYPE_ASSETLIST = 0x3F,
  ASSET_TYPE_REPORT = 0x40,
  ASSET_TYPE_DEPEND = 0x41,
  ASSET_TYPE_FULL_COUNT = 0x42,
};

template<typename T> union XAssetPoolEntry
{
	T entry;
	T * next;							//Pointer to the next asset, only if this asset is free
};

template<typename T, int count> struct XAssetPool
{
	T * freeHead;										//Pointer to the first free asset
	XAssetPoolEntry<T> entries[count];
};

enum AssetEntryType
{
	ASSET_ENTRY_BYTE,
	ASSET_ENTRY_BOOL,
	ASSET_ENTRY_BOOL_AS_INT,
	ASSET_ENTRY_SHORT,
	ASSET_ENTRY_UNSIGNED_SHORT,
	ASSET_ENTRY_TIME_AS_INT,
	ASSET_ENTRY_INT,
	ASSET_ENTRY_UNSIGNED_INT,
	ASSET_ENTRY_FLOAT,
	ASSET_ENTRY_STRING,
	ASSET_ENTRY_SCRIPT_STRING,
	ASSET_ENTRY_ASSET_PTR,
	ASSET_ENTRY_CONTAINED,
	ASSET_ENTRY_CONTAINED_REVERSED,
	ASSET_ENTRY_EMBEDDED,
	ASSET_ENTRY_EMBEDDED_REVERSED,
	ASSET_ENTRY_ENUM,
	ASSET_ENTRY_ENUM_SHORT
};
 
enum surfaceNames_t
{
  bark,
  brick,
  carpet,
  cloth,
  concrete,
  dirt,
  flesh,
  foliage,
  glass,
  grass,
  gravel,
  ice,
  metal,
  mud,
  paper,
  plaster,
  rock,
  sand,
  snow,
  water,
  wood,
  asphalt,
  ceramic,
  plastic,
  rubber,
  cushion,
  fruit,
  paintedmetal,
  player,
  tallgrass,
  riotshield_surf,
  opaqueglass
};

struct AssetEntry
{
	char * name;
	int offset;
	AssetEntryType type;
	AssetEntry * next;
	unsigned int enumCount;
};

bool DumpAssetEntry(FILE * writeLog, AssetEntryType currentEntryType, const char * currentEntryName, void * assetData, AssetEntry * containedItems = 0, int enumCount = 0, const char * parentName = "");
bool WriteAssetEntry(AssetEntry * currentEntries, char * tokenName, char * tokenValue, void * assetHeader, const char * parentName = "", bool parentReversed = false);
extern AssetEntry OffsetEntry[];
extern AssetEntry MinMax_FloatEntry[];

struct XModel;
struct Material;
struct FxEffectDef;
struct WeaponAttachment;
struct WeaponAttachmentUnique;
struct WeaponCamo;
struct TracerDef;

typedef unsigned short ScriptString;

#pragma region physpreset (0x01)
struct PhysPreset
{
  const char *name;
  int flags;
  float mass;
  float bounce;
  float friction;
  float bulletForceScale;
  float explosiveForceScale;
  const char *sndAliasPrefix;
  float piecesSpreadFraction;
  float piecesUpwardVelocity;
  int canFloat;
  float gravityScale;
  vec3_t centerOfMassOffset;
  vec3_t buoyancyBoxMin;
  vec3_t buoyancyBoxMax;

  int dumpPhysPreset();
};

typedef void (__cdecl * Load_PhysPresetAsset_t)(PhysPreset **physPreset);
extern Load_PhysPresetAsset_t Load_PhysPresetAsset;
extern AssetEntry PhysPresetEntries[];
void Load_PhysPresetAssetSaveStub(PhysPreset ** input);
void Load_PhysPresetAssetHook(PhysPreset ** input);
#pragma endregion

#pragma region physconstraints (0x02)
enum ConstraintType
{
  CONSTRAINT_NONE = 0x0,
  CONSTRAINT_POINT = 0x1,
  CONSTRAINT_DISTANCE = 0x2,
  CONSTRAINT_HINGE = 0x3,
  CONSTRAINT_JOINT = 0x4,
  CONSTRAINT_ACTUATOR = 0x5,
  CONSTRAINT_FAKE_SHAKE = 0x6,
  CONSTRAINT_LAUNCH = 0x7,
  CONSTRAINT_ROPE = 0x8,
  CONSTRAINT_LIGHT = 0x9,
  NUM_CONSTRAINT_TYPES
};

extern const char * ConstraintType_s[];
 
enum AttachPointType
{
  ATTACH_POINT_WORLD = 0x0,
  ATTACH_POINT_DYNENT = 0x1,
  ATTACH_POINT_ENT = 0x2,
  ATTACH_POINT_BONE = 0x3
};

extern const char * AttachPointType_s[];

struct PhysConstraint
{
  ScriptString targetname;
  ConstraintType type;
  AttachPointType attach_point_type1;
  int target_index1;
  ScriptString target_ent1;
  const char *target_bone1;
  AttachPointType attach_point_type2;
  int target_index2;
  ScriptString target_ent2;
  const char *target_bone2;
  vec3_t offset;
  vec3_t pos;
  vec3_t pos2;
  vec3_t dir;
  int flags;
  int timeout;
  int min_health;
  int max_health;
  float distance;
  float damp;
  float power;
  vec3_t scale;
  float spin_scale;
  float minAngle;
  float maxAngle;
  Material *material;
  int constraintHandle;
  int rope_index;
  int centity_num[4];
};
 
struct PhysConstraints
{
  const char * name;
  unsigned int count;
  PhysConstraint data[0x10];

  int dumpPhysConstraints();
};

typedef void (__cdecl * Load_PhysConstraintsAsset_t)(PhysConstraints **physConstraints);
extern Load_PhysConstraintsAsset_t Load_PhysConstraintsAsset;
extern AssetEntry PhysConstraintEntries[];
extern AssetEntry PhysConstraintsEntries[];
void Load_PhysConstraintsAssetSaveStub(PhysConstraints ** input);
void Load_PhysConstraintsAssetHook(PhysConstraints ** input);
#pragma endregion

#pragma region destructibledef (0x03)
struct DestructibleStage
{
  ScriptString showBone;
  float breakHealth;
  float maxTime;
  unsigned int flags;
  FxEffectDef *breakEffect;
  const char *breakSound;
  const char *breakNotify;
  const char *loopSound;
  XModel *spawnModel[3];
  PhysPreset *physPreset;
};

struct DestructiblePiece
{
  DestructibleStage stages[5];
  char parentPiece;
  float parentDamagePercent;
  float bulletDamageScale;
  float explosiveDamageScale;
  float meleeDamageScale;
  float impactDamageScale;
  float entityDamageTransfer;
  PhysConstraints *physConstraints;
  int health;
  const char *damageSound;
  FxEffectDef *burnEffect;
  const char *burnSound;
  ScriptString enableLabel;
  int hideBones[5];

  int dumpDestructiblePiece(const char * parentName, int pieceIndex);
};

struct DestructibleDef
{
  const char *name;
  XModel *model;
  XModel *pristineModel;
  int numPieces;
  DestructiblePiece *pieces;
  int clientOnly;

  int dumpDestructibleDef();
};

typedef void (__cdecl * Load_DestructibleDefAsset_t)(DestructibleDef **destructibleDef);
extern Load_DestructibleDefAsset_t Load_DestructibleDefAsset;
extern AssetEntry DestructibleDefEntries[];
extern AssetEntry DestructiblePieceEntries[];
void Load_DestructibleDefAssetSaveStub(DestructibleDef ** input);
void Load_DestructibleDefAssetHook(DestructibleDef ** input);
#pragma endregion

#pragma region image (0x09)
struct CardMemory
{
  int platform[1];
};

struct GfxImage
{
	D3DBaseTexture basemap;
	char unknown2;
	char unknown3;
	char unknown4;
	char unknown5;
  __declspec(align(4)) CardMemory cardMemory; //defines the size
  unsigned __int16 width;
  unsigned __int16 height;
  unsigned __int16 depth;
  char levelCount;
  char streaming;
  unsigned int baseSize;
  char *pixels;
	char unknownData2[0x80];
  const char *name;
  unsigned int hash;
};
#pragma endregion

#pragma region map_ents (0x11)
struct TriggerModel
{
  int contents;
  unsigned __int16 hullCount;
  unsigned __int16 firstHull;
};

struct Bounds
{
  vec3_t midPoint;
  vec3_t halfSize;
};
 
struct TriggerHull
{
  Bounds bounds;
  int contents;
  unsigned __int16 slabCount;
  unsigned __int16 firstSlab;
};
 
struct TriggerSlab
{
  vec3_t dir;
  float midPoint;
  float halfSize;
};
 
struct MapTriggers
{
  unsigned int count;
  TriggerModel *models;
  unsigned int hullCount;
  TriggerHull *hulls;
  unsigned int slabCount;
  TriggerSlab *slabs;
};
 
struct MapEnts
{
  const char *name;
  char *entityString;
  int numEntityChars;
  MapTriggers trigger;

  int dumpMapEntities();
};

typedef void (__cdecl * Load_MapEntsAsset_t)(MapEnts **mapEnts);
extern Load_MapEntsAsset_t Load_MapEntsAsset;
void Load_MapEntsAssetSaveStub(MapEnts ** input);
void Load_MapEntsAssetHook(MapEnts ** input);
#pragma endregion

#pragma region lightdef (0x13)
#pragma pack(push, 4)
struct GfxLightImage
{
  GfxImage *image;
  char samplerState;
};
#pragma pack(pop)
 
struct GfxLightDef
{
  const char *name;
  GfxLightImage attenuation;
  int lmapLookupStart;

  int dumpGfxLightDef();
};

typedef void (__cdecl * Load_GfxLightDefAsset_t)(GfxLightDef **gfxLightDef);
extern Load_GfxLightDefAsset_t Load_GfxLightDefAsset;
void Load_GfxLightDefAssetSaveStub(GfxLightDef ** input);
void Load_GfxLightDefAssetHook(GfxLightDef ** input);
#pragma endregion

#pragma region localize (0x19)
struct LocalizeEntry
{
  const char *value;
  const char *name;

  int DumpLocalizedString();
};

typedef void (__cdecl * Load_LocalizeEntryAsset_t)(LocalizeEntry **localizeEntry);
extern Load_LocalizeEntryAsset_t Load_LocalizeEntryAsset;
void Load_LocalizeEntryAssetSaveStub(LocalizeEntry ** input);
void Load_LocalizeEntryAssetHook(LocalizeEntry ** input);
#pragma endregion

#pragma region weapon (0x1A)
enum AnimationType : int
{
  none = 0,
  default = 1,
  other = 2,
  sniper = 3,
  m203 = 4,
  hold = 5,
  briefcase = 6,
  reviver = 7,
  radio = 8,
  dualwield = 9,
  remotecontrol = 10,
  crossbow = 11,
  minigun = 12,
  beltfed = 13, 
  g11 = 14,
  rearclip = 15,
  handleclip = 16,
  rearclipsniper = 17,
  ballisticknife = 18,
  singleknife = 19,
  nopump = 20,
  hatchet = 21,
  grimreaper = 22,
  zipline = 23,
  riotshield_anim = 24,
  tablet = 25,
  turned = 26,
  screecher = 27,
  PLAYER_ANIM_TYPE_MAX
};
 
enum weapType_t : int
{
  WEAPTYPE_BULLET = 0,
  WEAPTYPE_GRENADE = 1,
  WEAPTYPE_PROJECTILE = 2,
  WEAPTYPE_BINOCULARS = 3,
  WEAPTYPE_GAS = 4,
  WEAPTYPE_BOMB = 5,
  WEAPTYPE_MINE = 6,
  WEAPTYPE_MELEE = 7,
  WEAPTYPE_RIOTSHIELD = 8,
  WEAPTYPE_MAX
};
 
enum weapClass_t : int
{
  WEAPCLASS_RIFLE = 0,
  WEAPCLASS_MG = 1,
  WEAPCLASS_SMG = 2,
  WEAPCLASS_SPREAD = 3,
  WEAPCLASS_PISTOL = 4,
  WEAPCLASS_GRENADE = 5,
  WEAPCLASS_ROCKETLAUNCHER = 6,
  WEAPCLASS_TURRET = 7,
  WEAPCLASS_NON_PLAYER = 8,
  WEAPCLASS_GAS = 9,
  WEAPCLASS_ITEM  = 10,
  WEAPCLASS_MELEE = 11,
  WEAPCLASS_KILLSTREAK_ALT_STORED_WEAPON = 12,
  WEAPCLASS_PISTOL_SPREAD = 13,
  WEAPCLASS_MAX
};
 
enum weaponIconRatioType_t : int
{
  WEAPON_ICON_RATIO_1TO1 = 0,
  WEAPON_ICON_RATIO_2TO1 = 1,
  WEAPON_ICON_RATIO_4TO1 = 2,
  WEAPON_ICON_RATIO_MAX
};
 
enum PenetrateType : int
{
  PENETRATE_TYPE_NONE = 0,
  PENETRATE_TYPE_SMALL = 1,
  PENETRATE_TYPE_MEDIUM = 2,
  PENETRATE_TYPE_LARGE = 3,
  PENETRATE_TYPE_MAX 
};
 
enum weapStance_t : int
{
  WEAPSTANCE_STAND = 0x0,
  WEAPSTANCE_DUCK = 0x1,
  WEAPSTANCE_PRONE = 0x2,
  WEAPSTANCE_MAX
};
 
enum ammoCounterClipType_t : int
{
  AMMO_COUNTER_CLIP_NONE = 0,
  AMMO_COUNTER_CLIP_MAGAZINE = 1,
  AMMO_COUNTER_CLIP_SHORTMAGAZINE = 2,
  AMMO_COUNTER_CLIP_SHOTGUN = 3,
  AMMO_COUNTER_CLIP_ROCKET = 4,
  AMMO_COUNTER_CLIP_BELTFED = 5,
  AMMO_COUNTER_CLIP_ALTWEAPON = 6,
  AMMO_COUNTER_CLIP_MAX
};
 
enum weapOverlayReticle_t
{
  WEAPOVERLAYRETICLE_NONE = 0x0,
  WEAPOVERLAYRETICLE_CROSSHAIR = 0x1,
  WEAPOVERLAYRETICLE_MAX
};
 
enum weapOverlayInterface_t
{
  WEAPOVERLAYINTERFACE_NONE = 0x0,
  WEAPOVERLAYINTERFACE_JAVELIN = 0x1,
  WEAPOVERLAYINTERFACE_TURRETSCOPE = 0x2,
  WEAPOVERLAYINTERFACE_MAX
};
 
enum weapInventoryType_t : int
{
  WEAPINVENTORY_PRIMARY = 0,
  WEAPINVENTORY_OFFHAND = 1,
  WEAPINVENTORY_ITEM = 2,
  WEAPINVENTORY_ALTMODE = 3,
  WEAPINVENTORY_MELEE = 4,
  WEAPINVENTORY_DW_LEFT_HAND = 5,
  WEAPINVENTORY_MAX
};
 
enum ImpactType : int
{
  IMPACT_TYPE_NONE = 0,
  IMPACT_TYPE_BULLET_SMALL = 1,
  IMPACT_TYPE_BULLET_LARGE = 2,
  IMPACT_TYPE_BULLET_AP = 3,
  IMPACT_TYPE_BULLET_XTREME = 4,
  IMPACT_TYPE_SHOTGUN = 5,
  IMPACT_TYPE_GRENADE_BOUNCE = 6,
  IMPACT_TYPE_GRENADE_EXPLODE = 7,
  IMPACT_TYPE_RIFLE_GRENADE = 8,
  IMPACT_TYPE_ROCKET_EXPLODE = 9,
  IMPACT_TYPE_ROCKET_EXPLODE_XTREME = 10,
  IMPACT_TYPE_PROJECTILE_DUD = 11,
  IMPACT_TYPE_MORTAR_SHELL = 12,
  IMPACT_TYPE_TANK_SHELL = 13,
  IMPACT_TYPE_BOLT = 14,
  IMPACT_TYPE_BLADE = 15,
  IMPACT_TYPE_MAX
};
 
enum weapFireType_t : int
{
  WEAPON_FIRETYPE_FULLAUTO = 0,
  WEAPON_FIRETYPE_SINGLESHOT = 1,
  WEAPON_FIRETYPE_2ROUNDBURST = 2,
  WEAPON_FIRETYPE_3ROUNDBURST = 3,
  WEAPON_FIRETYPE_4ROUNDBURST = 4,
  WEAPON_FIRETYPE_5ROUNDBURST = 5,
  WEAPON_FIRETYPE_STACKEDFIRE = 6,
  WEAPON_FIRETYPE_MINIGUN = 7,
  WEAPON_FIRETYPE_CHARGESHOT = 8,
  WEAPON_FIRETYPE_JETGUN = 9,
  WEAPON_FIRETYPE_MAX
};
 
enum weapClipType_t : int
{
  WEAPON_CLIPTYPE_BOTTOM = 0x0,
  WEAPON_CLIPTYPE_TOP = 0x1,
  WEAPON_CLIPTYPE_LEFT = 0x2,
  WEAPON_CLIPTYPE_DP28 = 0x3,
  WEAPON_CLIPTYPE_PTRS = 0x4,
  WEAPON_CLIPTYPE_LMG = 0x5,
  WEAPON_CLIPTYPECOUNT = 0x6,
};
 
enum barrelType_t : int
{
  BARREL_TYPE_SINGLE = 0x0,
  BARREL_TYPE_DUAL = 0x1,
  BARREL_TYPE_DUAL_ALTERNATE = 0x2,
  BARREL_TYPE_QUAD = 0x3,
  BARREL_TYPE_QUAD_ALTERNATE = 0x4,
  BARREL_TYPE_QUAD_DOUBLE_ALTERNATE = 0x5,
  BARREL_TYPE_COUNT = 0x6
};
 
enum WeapStickinessType
{
  WEAPSTICKINESS_NONE = 0x0,
  WEAPSTICKINESS_ALL = 0x1,
  WEAPSTICKINESS_ALL_NO_SENTIENTS = 0x2,
  WEAPSTICKINESS_GROUND = 0x3,
  WEAPSTICKINESS_GROUND_WITH_YAW = 0x4,
  WEAPSTICKINESS_FLESH = 0x5,
  WEAPSTICKINESS_COUNT = 0x6
};
 
enum WeapRotateType
{
  WEAPROTATE_GRENADE_ROTATE = 0x0,
  WEAPROTATE_BLADE_ROTATE = 0x1,
  WEAPROTATE_CYLINDER_ROTATE = 0x2,
  WEAPROTATE_COUNT = 0x3
};
 
enum guidedMissileType_t
{
  MISSILE_GUIDANCE_NONE = 0x0,
  MISSILE_GUIDANCE_SIDEWINDER = 0x1,
  MISSILE_GUIDANCE_HELLFIRE = 0x2,
  MISSILE_GUIDANCE_JAVELIN = 0x3,
  MISSILE_GUIDANCE_BALLISTIC = 0x4,
  MISSILE_GUIDANCE_WIRE = 0x5,
  MISSILE_GUIDANCE_TV = 0x6,
  MISSILE_GUIDANCE_DRONE = 0x7,
  MISSILE_GUIDANCE_HEAT = 0x8,
  MISSILE_GUIDANCE_MAX
};
 
enum hitLocation_t
{
  HITLOC_NONE = 0x0,
  HITLOC_HELMET = 0x1,
  HITLOC_HEAD = 0x2,
  HITLOC_NECK = 0x3,
  HITLOC_TORSO_UPR = 0x4,
  HITLOC_TORSO_MID = 0x5,
  HITLOC_TORSO_LWR = 0x6,
  HITLOC_R_ARM_UPR = 0x7,
  HITLOC_L_ARM_UPR = 0x8,
  HITLOC_R_ARM_LWR = 0x9,
  HITLOC_L_ARM_LWR = 0xA,
  HITLOC_R_HAND = 0xB,
  HITLOC_L_HAND = 0xC,
  HITLOC_R_LEG_UPR = 0xD,
  HITLOC_L_LEG_UPR = 0xE,
  HITLOC_R_LEG_LWR = 0xF,
  HITLOC_L_LEG_LWR = 0x10,
  HITLOC_R_FOOT = 0x11,
  HITLOC_L_FOOT = 0x12,
  HITLOC_GUN = 0x13,
  HITLOC_RIOT = 0x14,
  HITLOC_NUM = 0x15
};

enum activeReticleType_t
{
  VEH_ACTIVE_RETICLE_NONE = 0x0,
  VEH_ACTIVE_RETICLE_PIP_ON_A_STICK = 0x1,
  VEH_ACTIVE_RETICLE_BOUNCING_DIAMOND = 0x2,
  VEH_ACTIVE_RETICLE_MISSILE_LOCK = 0x3,
  VEH_ACTIVE_RETICLE_COUNT = 0x4
};

enum weapProjExposion_t
{
  WEAPPROJEXP_GRENADE = 0x0,
  WEAPPROJEXP_ROCKET = 0x1,
  WEAPPROJEXP_FLASHBANG = 0x2,
  WEAPPROJEXP_NONE = 0x3,
  WEAPPROJEXP_DUD = 0x4,
  WEAPPROJEXP_SMOKE = 0x5,
  WEAPPROJEXP_HEAVY = 0x6,
  WEAPPROJEXP_FIRE = 0x7,
  WEAPPROJEXP_NAPALMBLOB = 0x8,
  WEAPPROJEXP_BOLT = 0x9,
  WEAPPROJEXP_SHRAPNELSPAN = 0xA,
  WEAPPROJEXP_NUM = 0xB
};
 
struct ProjectileExplosionEffect
{
  FxEffectDef * projExplosionEffect;
  bool projExplosionEffectForceNormalUp;
};
 
struct flameTable
{
  float streamChunkGravityStart;
  float streamChunkGravityEnd;
  float streamChunkMaxSize;
  float streamChunkStartSize;
  float streamChunkEndSize;
  float streamChunkStartSizeRand;
  float streamChunkEndSizeRand;
  float streamChunkDistScalar;
  float streamChunkDistSwayScale;
  float streamChunkDistSwayVelMax;
  float streamChunkSpeed;
  float streamChunkDecel;
  float streamChunkVelocityAddScale;
  float streamChunkDuration;
  float streamChunkDurationScaleMaxVel;
  float streamChunkDurationVelScalar;
  float streamChunkSizeSpeedScale;
  float streamChunkSizeAgeScale;
  float streamChunkSpawnFireIntervalSt;
  float streamChunkSpawnFireIntervalEn;
  float streamChunkSpawnFireMinLifeFra;
  float streamChunkSpawnFireMaxLifeFra;
  float streamChunkFireMinLifeFrac;
  float streamChunkFireMinLifeFracStar;
  float streamChunkFireMinLifeFracEnd;
  float streamChunkDripsMinLifeFrac;
  float streamChunkDripsMinLifeFracSta;
  float streamChunkDripsMinLifeFracEnd;
  float streamChunkRotationRange;
  float streamSizeRandSinWave;
  float streamSizeRandCosWave;
  float streamDripsChunkInterval;
  float streamDripsChunkMinFrac;
  float streamDripsChunkRandFrac;
  float streamSmokeChunkInterval;
  float streamSmokeChunkMinFrac;
  float streamSmokeChunkRandFrac;
  float streamChunkCullDistSizeFrac;
  float streamChunkCullMinLife;
  float streamChunkCullMaxLife;
  float streamFuelSizeStart;
  float streamFuelSizeEnd;
  float streamFuelLength;
  float streamFuelNumSegments;
  float streamFuelAnimLoopTime;
  float streamFlameSizeStart;
  float streamFlameSizeEnd;
  float streamFlameLength;
  float streamFlameNumSegments;
  float streamFlameAnimLoopTime;
  float streamPrimaryLightRadius;
  float streamPrimaryLightRadiusFlutte;
  float streamPrimaryLightR;
  float streamPrimaryLightG;
  float streamPrimaryLightB;
  float streamPrimaryLightFlutterR;
  float streamPrimaryLightFlutterG;
  float streamPrimaryLightFlutterB;
  float fireLife;
  float fireLifeRand;
  float fireSpeedScale;
  float fireSpeedScaleRand;
  float fireVelocityAddZ;
  float fireVelocityAddZRand;
  float fireVelocityAddSideways;
  float fireGravity;
  float fireGravityEnd;
  float fireMaxRotVel;
  float fireFriction;
  float fireEndSizeAdd;
  float fireStartSizeScale;
  float fireEndSizeScale;
  float fireBrightness;
  float dripsLife;
  float dripsLifeRand;
  float dripsSpeedScale;
  float dripsSpeedScaleRand;
  float dripsVelocityAddZ;
  float dripsVelocityAddZRand;
  float dripsVelocityAddSideways;
  float dripsGravity;
  float dripsGravityEnd;
  float dripsMaxRotVel;
  float dripsFriction;
  float dripsEndSizeAdd;
  float dripsStartSizeScale;
  float dripsEndSizeScale;
  float dripsBrightness;
  float smokeLife;
  float smokeLifeRand;
  float smokeSpeedScale;
  float smokeVelocityAddZ;
  float smokeGravity;
  float smokeGravityEnd;
  float smokeMaxRotation;
  float smokeMaxRotVel;
  float smokeFriction;
  float smokeEndSizeAdd;
  float smokeStartSizeAdd;
  float smokeOriginSizeOfsZScale;
  float smokeOriginOfsZ;
  float smokeFadein;
  float smokeFadeout;
  float smokeMaxAlpha;
  float smokeBrightness;
  float smokeOriginOffset;
  float collisionSpeedScale;
  float collisionVolumeScale;
  const char * name;
  Material * fire;
  Material * smoke;
  Material * heat;
  Material * drips;
  Material * streamFuel;
  Material * streamFuel2;
  Material * streamFlame;
  Material * streamFlame2;
  const char * flameOffLoopSound;
  const char * flameIgniteSound;
  const char * flameOnLoopSound;
  const char * flameCooldownSound;
};
 
enum OffhandClass
{
  OFFHAND_CLASS_NONE = 0x0,
  OFFHAND_CLASS_FRAG_GRENADE = 0x1,
  OFFHAND_CLASS_SMOKE_GRENADE = 0x2,
  OFFHAND_CLASS_FLASH_GRENADE = 0x3,
  OFFHAND_CLASS_GEAR = 0x4,
  OFFHAND_CLASS_SUPPLYDROP_MARKER = 0x5,
  OFFHAND_CLASS_COUNT = 0x6
};
 
enum OffhandSlot
{
  OFFHAND_SLOT_NONE = 0x0,
  OFFHAND_SLOT_LETHAL_GRENADE = 0x1,
  OFFHAND_SLOT_TACTICAL_GRENADE = 0x2,
  OFFHAND_SLOT_EQUIPMENT = 0x3,
  OFFHAND_SLOT_SPECIFIC_USE = 0x4,
  OFFHAND_SLOT_COUNT = 0x5
};

enum weapAnimFiles_t
{
  WEAP_ANIM_ROOT = 0x0,
  WEAP_ANIM_IDLE = 0x1,
  WEAP_ANIM_EMPTY_IDLE = 0x2,
  WEAP_ANIM_FIRE_INTRO = 0x3,
  WEAP_ANIM_FIRE = 0x4,
  WEAP_ANIM_HOLD_FIRE = 0x5,
  WEAP_ANIM_LASTSHOT = 0x6,
  WEAP_ANIM_FINALSHOT = 0x7,
  WEAP_ANIM_RECHAMBER = 0x8,
  WEAP_ANIM_MELEE = 0x9,
  WEAP_ANIM_MELEE1 = 0xA,
  WEAP_ANIM_MELEE2 = 0xB,
  WEAP_ANIM_MELEE3 = 0xC,
  WEAP_ANIM_MELEE_EMPTY = 0xD,
  WEAP_ANIM_MELEE_CHARGE = 0xE,
  WEAP_ANIM_MELEE_CHARGE_EMPTY = 0xF,
  WEAP_ANIM_RELOAD = 0x10,
  WEAP_ANIM_RELOAD_RIGHT = 0x11,
  WEAP_ANIM_RELOAD_EMPTY = 0x12,
  WEAP_ANIM_RELOAD_START = 0x13,
  WEAP_ANIM_RELOAD_END = 0x14,
  WEAP_ANIM_RELOAD_QUICK = 0x15,
  WEAP_ANIM_RELOAD_QUICK_EMPTY = 0x16,
  WEAP_ANIM_RAISE = 0x17,
  WEAP_ANIM_FIRST_RAISE = 0x18,
  WEAP_ANIM_DROP = 0x19,
  WEAP_ANIM_ALT_RAISE = 0x1A,
  WEAP_ANIM_ALT_DROP = 0x1B,
  WEAP_ANIM_QUICK_RAISE = 0x1C,
  WEAP_ANIM_QUICK_DROP = 0x1D,
  WEAP_ANIM_EMPTY_RAISE = 0x1E,
  WEAP_ANIM_EMPTY_DROP = 0x1F,
  WEAP_ANIM_SPRINT_IN = 0x20,
  WEAP_ANIM_SPRINT_LOOP = 0x21,
  WEAP_ANIM_SPRINT_OUT = 0x22,
  WEAP_ANIM_SPRINT_EMPTY_IN = 0x23,
  WEAP_ANIM_SPRINT_EMPTY_LOOP = 0x24,
  WEAP_ANIM_SPRINT_EMPTY_OUT = 0x25,
  WEAP_ANIM_LOWREADY_IN = 0x26,
  WEAP_ANIM_LOWREADY_LOOP = 0x27,
  WEAP_ANIM_LOWREADY_OUT = 0x28,
  WEAP_ANIM_CONT_FIRE_IN = 0x29,
  WEAP_ANIM_CONT_FIRE_LOOP = 0x2A,
  WEAP_ANIM_CONT_FIRE_OUT = 0x2B,
  WEAP_ANIM_CRAWL_IN = 0x2C,
  WEAP_ANIM_CRAWL_FORWARD = 0x2D,
  WEAP_ANIM_CRAWL_BACK = 0x2E,
  WEAP_ANIM_CRAWL_RIGHT = 0x2F,
  WEAP_ANIM_CRAWL_LEFT = 0x30,
  WEAP_ANIM_CRAWL_OUT = 0x31,
  WEAP_ANIM_CRAWL_EMPTY_IN = 0x32,
  WEAP_ANIM_CRAWL_EMPTY_FORWARD = 0x33,
  WEAP_ANIM_CRAWL_EMPTY_BACK = 0x34,
  WEAP_ANIM_CRAWL_EMPTY_RIGHT = 0x35,
  WEAP_ANIM_CRAWL_EMPTY_LEFT = 0x36,
  WEAP_ANIM_CRAWL_EMPTY_OUT = 0x37,
  WEAP_ANIM_DEPLOY = 0x38,
  WEAP_ANIM_BREAKDOWN = 0x39,
  WEAP_ANIM_DETONATE = 0x3A,
  WEAP_ANIM_NIGHTVISION_WEAR = 0x3B,
  WEAP_ANIM_NIGHTVISION_REMOVE = 0x3C,
  WEAP_ANIM_ADS_FIRE = 0x3D,
  WEAP_ANIM_ADS_LASTSHOT = 0x3E,
  WEAP_ANIM_ADS_FIRE_INTRO = 0x3F,
  WEAP_ANIM_ADS_RECHAMBER = 0x40,
  WEAP_ANIM_DTP_IN = 0x41,
  WEAP_ANIM_DTP_LOOP = 0x42,
  WEAP_ANIM_DTP_OUT = 0x43,
  WEAP_ANIM_DTP_EMPTY_IN = 0x44,
  WEAP_ANIM_DTP_EMPTY_LOOP = 0x45,
  WEAP_ANIM_DTP_EMPTY_OUT = 0x46,
  WEAP_ANIM_SLIDE_IN = 0x47,
  WEAP_ANIM_MANTLE = 0x48,
  WEAP_ANIM_CAMERA_SPRINT_LOOP = 0x49,
  WEAP_ANIM_CAMERA_DTP_IN = 0x4A,
  WEAP_ANIM_CAMERA_DTP_LOOP = 0x4B,
  WEAP_ANIM_CAMERA_DTP_OUT = 0x4C,
  WEAP_ANIM_CAMERA_MANTLE = 0x4D,
  WEAP_ANIM_FIRE_LEFT = 0x4E,
  WEAP_ANIM_LASTSHOT_LEFT = 0x4F,
  WEAP_ANIM_FINALSHOT_LEFT = 0x50,
  WEAP_ANIM_IDLE_LEFT = 0x51,
  WEAP_ANIM_EMPTY_IDLE_LEFT = 0x52,
  WEAP_ANIM_RELOAD_EMPTY_LEFT = 0x53,
  WEAP_ANIM_RELOAD_LEFT = 0x54,
  WEAP_ANIM_ADS_UP = 0x55,
  WEAP_ANIM_ADS_DOWN = 0x56,
  WEAP_ANIM_ADS_UP_OTHER_SCOPE = 0x57,
  NUM_WEAP_ANIMS = 0x58
};

enum meansOfDeath_t
{
  MOD_UNKNOWN = 0x0,
  MOD_PISTOL_BULLET = 0x1,
  MOD_RIFLE_BULLET = 0x2,
  MOD_GRENADE = 0x3,
  MOD_GRENADE_SPLASH = 0x4,
  MOD_PROJECTILE = 0x5,
  MOD_PROJECTILE_SPLASH = 0x6,
  MOD_MELEE = 0x7,
  MOD_BAYONET = 0x8,
  MOD_HEAD_SHOT = 0x9,
  MOD_CRUSH = 0xA,
  MOD_TELEFRAG = 0xB,
  MOD_FALLING = 0xC,
  MOD_SUICIDE = 0xD,
  MOD_TRIGGER_HURT = 0xE,
  MOD_EXPLOSIVE = 0xF,
  MOD_IMPACT = 0x10,
  MOD_BURNED = 0x11,
  MOD_HIT_BY_OBJECT = 0x12,
  MOD_DROWN = 0x13,
  MOD_GAS = 0x14,
  MOD_NUM = 0x15
};
 
struct WeaponDef
{
  const char *szOverlayName;
  XModel **gunXModel;
  XModel *handXModel;
  const char *szModeName;
  ScriptString (*noteTrackSoundMapKeys)[0x14];
  ScriptString (*notetrackSoundMapValues)[0x14];
  AnimationType playerAnimType;
  weapType_t weaponType;
  weapClass_t weaponClass;
  PenetrateType penetrateType;
  ImpactType impactType;
  weapInventoryType_t inventoryType;
  weapFireType_t fireType;							
  weapClipType_t clipType;
  barrelType_t barrelType;
  int itemIndex;
  const char * parentWeaponName;
  int iJamFireTime;
  int overheatWeapon;
  float overheatRate;
  float cooldownRate;
  float overheatEndVal;
  bool coolWhileFiring;
  bool fuelTankWeapon;
  int iTankLifeTime;
  OffhandClass offhandClass;
  OffhandSlot offhandSlot;
  weapStance_t stance;
  FxEffectDef * viewFlashEffect;
  FxEffectDef * worldFlashEffect;
  FxEffectDef * barrelCooldownEffect;
  int barrelCooldownMinCount;
  vec3_t vViewFlashOffset;
  vec3_t vWorldFlashOffset;
  char * pickupSound;
  char * pickupSoundPlayer;
  char * ammoPickupSound;
  char * ammoPickupSoundPlayer;
  char * projectileSound;
  char * pullbackSound;
  char * pullbackSoundPlayer;
  char * fireSound;
  char * fireSoundPlayer;
  char * loopFireSound;
  char * loopFireSoundPlayer;
  char * loopFireEndSound;
  char * loopFireEndSoundPlayer;
  char * startFireSound;
  char * stopFireSound;
  char * killcamStartFireSound;
  char * startFireSoundPlayer;
  char * stopFireSoundPlayer;
  char * killcamStartFireSoundPlayer;
  char * lastShotSound;
  char * lastShotSoundPlayer;
  char * emptyFireSound;
  char * emptyFireSoundPlayer;
  char * crackSound;
  char * whizbySound;
  char * meleeSwipeSound;
  char * meleeSwipeSoundPlayer;
  char * meleeHitSound;
  char * meleeMissSound;
  char * rechamberSound;
  char * rechamberSoundPlayer;
  char * reloadSound;
  char * reloadSoundPlayer;
  char * reloadEmptySound;
  char * reloadEmptySoundPlayer;
  char * reloadStartSound;
  char * reloadStartSoundPlayer;
  char * reloadEndSound;
  char * reloadEndSoundPlayer;
  char * rotateLoopSound;
  char * rotateLoopSoundPlayer;
  char * rotateStopSound;
  char * rotateStopSoundPlayer;
  char * deploySound;
  char * deploySoundPlayer;
  char * finishDeploySound;
  char * finishDeploySoundPlayer;
  char * breakdownSound;
  char * breakdownSoundPlayer;
  char * finishBreakdownSound;
  char * finishBreakdownSoundPlayer;
  char * detonateSound;
  char * detonateSoundPlayer;
  char * nightVisionWearSound;
  char * nightVisionWearSoundPlayer;
  char * nightVisionRemoveSound;
  char * nightVisionRemoveSoundPlayer;
  char * altSwitchSound;
  char * altSwitchSoundPlayer;
  char * raiseSound;
  char * raiseSoundPlayer;
  char * firstRaiseSound;
  char * firstRaiseSoundPlayer;
  char * adsRaiseSoundPlayer;
  char * adsLowerSoundPlayer;
  char * putawaySound;
  char * putawaySoundPlayer;
  char * overheatSound;
  char * overheatSoundPlayer;
  char * adsZoomSound;
  char * shellCasing;
  char * shellCasingPlayer;
  char * * bounceSounds;    //Refer to surfaceNames_t
  const char * standMountedWeapdef;
  const char * crouchMountedWeapdef;
  const char * proneMountedWeapdef;
  unsigned int standMountedWeapIndex;
  unsigned int crouchMountedWeapIndex;
  unsigned int proneMountedWeapIndex;
  FxEffectDef * viewShellEjectEffect;
  FxEffectDef * worldShellEjectEffect;
  FxEffectDef * viewLastShotEjectEffect;
  FxEffectDef * worldLastShotEjectEffect;
  vec3_t vViewShellEjectOffset;
  vec3_t vWorldShellEjectOffset;
  vec3_t vViewShellEjectRotation;
  vec3_t vWorldShellEjectRotation;
  Material *reticleCenter;
  Material *reticleSide;
  int iReticleCenterSize;
  int iReticleSideSize;
  int iReticleMinOfs;
  activeReticleType_t activeReticleType;
  vec3_t vStandMove;
  vec3_t vStandRot;
  vec3_t vDuckedOfs;
  vec3_t vDuckedMove;
  vec3_t vDuckedSprintOfs;
  vec3_t vDuckedSprintRot;
  vec2_t vDuckedSprintBob;
  float fDuckedSprintCycleScale;
  vec3_t vSprintOfs;
  vec3_t vSprintRot;
  vec2_t vSprintBob;
  float fSprintCycleScale;
  vec3_t vLowReadyOfs;
  vec3_t vLowReadyRot;
  vec3_t vRideOfs;
  vec3_t vRideRot;
  vec3_t vDtpOfs;
  vec3_t vDtpRot;
  vec2_t vDtpBob;
  float fDtpCycleScale;
  vec3_t vMantleOfs;
  vec3_t vMantleRot;
  vec3_t vSlideOfs;
  vec3_t vSlideRot;
  vec3_t vDuckedRot;
  vec3_t vProneOfs;
  vec3_t vProneMove;
  vec3_t vProneRot;
  vec3_t vStrafeMove;
  vec3_t vStrafeRot;
  float fPosMoveRate;
  float fPosProneMoveRate;
  float fStandMoveMinSpeed;
  float fDuckedMoveMinSpeed;
  float fProneMoveMinSpeed;
  float fPosRotRate;
  float fPosProneRotRate;
  float fStandRotMinSpeed;
  float fDuckedRotMinSpeed;
  float fProneRotMinSpeed;
  XModel * *worldModel;
  XModel *worldClipModel;
  XModel *rocketModel;
  XModel *mountedModel;
  XModel *additionalMeleeModel;
  Material * fireTypeIcon;
  Material * hudIcon;
  weaponIconRatioType_t hudIconRatio;
  Material * indicatorIcon;
  weaponIconRatioType_t indicatorIconRatio;
  Material * ammoCounterIcon;
  weaponIconRatioType_t ammoCounterIconRatio;
  ammoCounterClipType_t ammoCounterClip;
  int iStartAmmo;
  int iMaxAmmo;
  int shotCount;
  const char *szSharedAmmoCapName;
  int iSharedAmmoCapIndex;
  int iSharedAmmoCap;
  bool unlimitedAmmo;
  bool ammoCountClipRelative;
  int damage[6];
  float damageRange[6];
  int minPlayerDamage;
  float damageDuration;
  float damageInterval;
  int playerDamage;
  int iMeleeDamage;
  int iDamageType;
  ScriptString explosionTag;
  int iFireDelay;
  int iMeleeDelay;
  int meleeChargeDelay;
  int iDetonateDelay;
  int iSpinUpTime;
  int iSpinDownTime;
  float spinRate;
  const char *spinLoopSound;
  const char *spinLoopSoundPlayer;
  const char *startSpinSound;
  const char *startSpinSoundPlayer;
  const char *stopSpinSound;
  const char *stopSpinSoundPlayer;
  bool applySpinPitch;
  int iFireTime;
  int iLastFireTime;
  int iRechamberTime;
  int iRechamberBoltTime;
  int iHoldFireTime;
  int iDetonateTime;
  int iMeleeTime;
  int iBurstDelayTime;
  int meleeChargeTime;
  int iReloadTimeRight;
  int iReloadTimeLeft;
  int reloadShowRocketTime;
  int iReloadEmptyTimeLeft;
  int iReloadAddTime;
  int iReloadEmptyAddTime;
  int iReloadQuickAddTime;
  int iReloadQuickEmptyAddTime;
  int iReloadStartTime;
  int iReloadStartAddTime;
  int iReloadEndTime;
  int iDropTime;
  int iRaiseTime;
  int iAltDropTime;
  int quickDropTime;
  int quickRaiseTime;
  int iFirstRaiseTime;
  int iEmptyRaiseTime;
  int iEmptyDropTime;
  int sprintInTime;
  int sprintLoopTime;
  int sprintOutTime;
  int lowReadyInTime;
  int lowReadyLoopTime;
  int lowReadyOutTime;
  int contFireInTime;
  int contFireLoopTime;
  int contFireOutTime;
  int dtpInTime;
  int dtpLoopTime;
  int dtpOutTime;
  int crawlInTime;
  int crawlForwardTime;
  int crawlBackTime;
  int crawlRightTime;
  int crawlLeftTime;
  int crawlOutFireTime;
  int crawlOutTime;
  int slideInTime;
  int deployTime;
  int breakdownTime;
  int iFlourishTime;
  int nightVisionWearTime;
  int nightVisionWearTimeFadeOutEnd;
  int nightVisionWearTimePowerUp;
  int nightVisionRemoveTime;
  int nightVisionRemoveTimePowerDown;
  int nightVisionRemoveTimeFadeInStart;
  int fuseTime;
  int aiFuseTime;
  int lockOnRadius;
  int lockOnSpeed;
  bool requireLockonToFire;
  bool noAdsWhenMagEmpty;
  bool avoidDropCleanup;
  unsigned int stackFire;
  float stackFireSpread;
  float stackFireAccuracyDecay;
  const char *stackSound;
  float autoAimRange;
  float aimAssistRange;
  bool mountableWeapon;
  float aimPadding;
  float enemyCrosshairRange;
  bool crosshairColorChange;
  float moveSpeedScale;
  float adsMoveSpeedScale;
  float sprintDurationScale;
  weapOverlayReticle_t adsOverlayReticle;
  weapOverlayInterface_t adsOverlayInterface;
  float overlayWidth;
  float overlayHeight;
  float fAdsBobFactor;
  float fAdsViewBobMult;
  bool bHoldBreathToSteady;
  float fHipSpreadStandMin;
  float fHipSpreadDuckedMin;
  float fHipSpreadProneMin;
  float hipSpreadStandMax;
  float hipSpreadDuckedMax;
  float hipSpreadProneMax;
  float fHipSpreadDecayRate;
  float fHipSpreadFireAdd;
  float fHipSpreadTurnAdd;
  float fHipSpreadMoveAdd;
  float fHipSpreadDuckedDecay;
  float fHipSpreadProneDecay;
  float fHipReticleSidePos;
  float fAdsIdleAmount;
  float fHipIdleAmount;
  float adsIdleSpeed;
  float hipIdleSpeed;
  float fIdleCrouchFactor;
  float fIdleProneFactor;
  float fGunMaxPitch;
  float fGunMaxYaw;
  float swayMaxAngle;
  float swayLerpSpeed;
  float swayPitchScale;
  float swayYawScale;
  float swayHorizScale;
  float swayVertScale;
  float swayShellShockScale;
  float adsSwayMaxAngle;
  float adsSwayLerpSpeed;
  float adsSwayPitchScale;
  float adsSwayYawScale;
  bool sharedAmmo;
  bool bRifleBullet;
  bool armorPiercing;
  bool bAirburstWeapon;
  bool bBoltAction;
  bool bUseAltTagFlash;
  bool bUseAntiLagRewind;
  bool bIsCarriedKillstreakWeapon;
  bool aimDownSight;
  bool bRechamberWhileAds;
  bool bReloadWhileAds;
  float adsViewErrorMin;
  float adsViewErrorMax;
  bool bCookOffHold;
  bool bClipOnly;
  bool bCanUseInVehicle;
  bool bNoDropsOrRaises;
  bool adsFireOnly;
  bool cancelAutoHolsterWhenEmpty;
  bool suppressAmmoReserveDisplay;
  bool laserSight;
  bool laserSightDuringNightvision;
  bool bHideThirdPerson;
  bool bHasBayonet;
  bool bDualWield;
  bool bExplodeOnGround;
  bool bThrowBack;
  bool bRetrievable;
  bool bDieOnRespawn;
  bool bNoThirdPersonDropsOrRaises;
  bool bContinuousFire;
  bool bNoPing;
  bool bForceBounce;
  bool bUseDroppedModelAsStowed;
  bool bNoQuickDropWhenEmpty;
  bool bKeepCrosshairWhenADS;
  bool bUseOnlyAltWeaoponHideTagsInAltMode;
  bool bAltWeaponAdsOnly;
  bool bAltWeaponDisableSwitching;
  Material *killIcon;
  weaponIconRatioType_t killIconRatio;
  bool flipKillIcon;
  bool bNoPartialReload;
  bool bSegmentedReload;
  bool bNoADSAutoReload;
  int iReloadAmmoAdd;
  int iReloadStartAdd;
  const char *szSpawnedGrenadeWeaponName;
  const char *szDualWieldWeaponName;
  unsigned int dualWieldWeaponIndex;
  int iDropAmmoMin;
  int iDropAmmoMax;
  int iDropClipAmmoMin;
  int iDropClipAmmoMax;
  int iShotsBeforeRechamber;
  bool blocksProne;
  bool bShowIndicator;
  int isRollingGrenade;
  int useBallisticPrediction;
  int isValuable;
  int isTacticalInsertion;
  bool isReviveWeapon;
  bool bUseRigidBodyOnVehicle;
  int iExplosionRadius;
  int iExplosionRadiusMin;
  int iIndicatorRadius;
  int iExplosionInnerDamage;
  int iExplosionOuterDamage;
  float damageConeAngle;
  int iProjectileSpeed;
  int iProjectileSpeedUp;
  int iProjectileSpeedRelativeUp;
  int iProjectileSpeedForward;
  float fProjectileTakeParentVelocity;
  int iProjectileActivateDist;
  float projLifetime;
  float timeToAccelerate;
  float projectileCurvature;
  XModel *projectileModel;
  weapProjExposion_t projExplosion;
  ProjectileExplosionEffect projExplosionEffect[5];
  FxEffectDef * projDudEffect;
  const char *projExplosionSound;
  const char *projDudSound;
  const char *mortarShellSound;
  const char *tankShellSound;
  bool bProjImpactExplode;
  bool bProjSentientImpactExplode;
  bool bProjExplodeWhenStationary;
  bool bBulletImpactExplode;
  WeapStickinessType stickiness;
  WeapRotateType rotateType;
  bool plantable;
  bool hasDetonator;
  bool timedDetonation;
  bool noCrumpleMissile;
  bool rotate;
  bool keepRolling; 
  bool holdButtonToThrow;
  bool offhandHoldIsCancelable;
  bool freezeMovementWhenFiring;
  float lowAmmoWarningThreshold;
  bool bDisallowAtMatchStart;
  float meleeChargeRange;
  bool bUseAsMelee;
  bool isCameraSensor;
  bool isAcousticSensor;
  bool isLaserSensor;
  bool isHoldUseGrenade;
  float *parallelBounce;
  float *perpendicularBounce;
  FxEffectDef * projTrailEffect;
  vec3_t vProjectileColor;
  guidedMissileType_t guidedMissileType;
  float maxSteeringAccel;
  int projIgnitionDelay;
  FxEffectDef *projIgnitionEffect;
  const char *projIgnitionSound;
  float fAdsAimPitch;
  float fAdsCrosshairInFrac;
  float fAdsCrosshairOutFrac;
  int adsGunKickReducedKickBullets;
  float adsGunKickReducedKickPercent;
  float fAdsGunKickPitchMin;
  float fAdsGunKickPitchMax;
  float fAdsGunKickYawMin;
  float fAdsGunKickYawMax;
  float fAdsGunKickAccel;
  float fAdsGunKickSpeedMax;
  float fAdsGunKickSpeedDecay;
  float fAdsGunKickStaticDecay;
  float fAdsViewKickPitchMin;
  float fAdsViewKickPitchMax;
  float fAdsViewKickMinMagnitude;
  float fAdsViewKickYawMin;
  float fAdsViewKickYawMax;
  float fAdsRecoilReductionRate;
  float fAdsRecoilReductionLimit;
  float fAdsRecoilReturnRate;
  float fAdsViewScatterMin;
  float fAdsViewScatterMax;
  float fAdsSpread;
  int hipGunKickReducedKickBullets;
  float hipGunKickReducedKickPercent;
  float fHipGunKickPitchMin;
  float fHipGunKickPitchMax;
  float fHipGunKickYawMin;
  float fHipGunKickYawMax;
  float fHipGunKickAccel;
  float fHipGunKickSpeedMax;
  float fHipGunKickSpeedDecay;
  float fHipGunKickStaticDecay;
  float fHipViewKickPitchMin;
  float fHipViewKickPitchMax;
  float fHipViewKickMinMagnitude;
  float fHipViewKickYawMin;
  float fHipViewKickYawMax;
  float fHipViewScatterMin;
  float fHipViewScatterMax;
  float fAdsViewKickCenterDuckedScale;
  float fAdsViewKickCenterProneScale;
  float fAntiQuickScopeTime;
  float fAntiQuickScopeScale;
  float fAntiQuickScopeSpreadMultiplier;
  float fAntiQuickScopeSpreadMax;
  float fAntiQuickScopeSwayFactor;
  float fightDist;
  float maxDist;
  const char * aiVsAiAccuracyGraphName;
  const char * aiVsPlayerAccuracyGraphName;
  vec2_t * aiVsAiAccuracyGraphKnots;
  vec2_t * aiVsPlayerAccuracyGraphKnots;
  vec2_t * aiVsAiOriginalAccuracyGraphKnots;
  vec2_t * aiVsPlayerOriginalAccuracyGraphKnots;
  int aiVsAiAccuracyGraphKnotCount;
  int aiVsPlayerAccuracyGraphKnotCount;
  int aiVsAiOriginalAccuracyGraphKnotCount;
  int aiVsPlayerOriginalAccuracyGraphKnotCount;
  int iPositionReloadTransTime;
  float leftArc;
  float rightArc;
  float topArc;
  float bottomArc;
  float accuracy;
  float aiSpread;
  float playerSpread;
  float minTurnSpeed[2];
  float maxTurnSpeed[2];
  float pitchConvergenceTime;
  float yawConvergenceTime;
  float suppressTime;
  float maxRange;
  float fAnimHorRotateInc;
  float fPlayerPositionDist;
  const char *szUseHintString;
  const char *dropHintString;
  int iUseHintStringIndex;
  int dropHintStringIndex;
  float horizViewJitter;
  float vertViewJitter;
  float cameraShakeScale;
  int cameraShakeDuration;
  int cameraShakeRadius;
  float explosionCameraShakeScale;
  int explosionCameraShakeDuration;
  int explosionCameraSHakeRadius;
  const char *szScript;
  float destabilizationRateTime;
  float destabilizationCurvatureMax;
  int destabilizeDistance;
  float * locationDamageMultipliers;      //Refer to hitLocation_t
  const char *fireRumble;
  const char *meleeImpactRumble;
  const char *reloadRumble;
  const char *explosionRumble;
  TracerDef *tracerType;
  TracerDef *enemyTracerType;
  float adsDofStart;
  float adsDofEnd;
  float hipDofStart;
  float hipDofEnd;
  float scanSpeed;
  float scanAccel;
  int scanPauseTime;
  const char * flameTableFirstPerson;
  const char * flameTableThirdPerson;
  flameTable * firstPersonFlameTable;
  flameTable * thirdPersonFlameTable;
  FxEffectDef * tagFx_preparationEffect;
  FxEffectDef * tagFlash_preparationEffect;
  bool doGibbing;
  float maxGibDistance;
  float altScopeADSTransInTime;
  float altScopeADSTransOutTime;
  int iIntroFireTime;
  int iIntroFireLength;
  FxEffectDef * meleeSwipeEffect;						//FxEffectDef
  FxEffectDef * meleeImpactEffect;						//FxEffectDef
  FxEffectDef * meleeImpactNoBloodEffect;
  const char *throwBackType;
  WeaponCamo * camo;
  float customFloat[3];
  int customBool[3];
};
 
struct WeaponVariantDef
{
  const char *szInternalName;
  int iVariantCount;
  WeaponDef *weapDef;
  const char *szDisplayName;
  const char *szAltWeaponName;
  const char *szAttachmentUnique;
  WeaponAttachment **attachments;				//Count = 0x3F
  WeaponAttachmentUnique **attachmentUniques;			//Count = 0x5F
  const char **szXAnims;					//Count = 0x58
  ScriptString (*hideTags)[0x20];
  XModel **attachViewModel;					//Count = 8
  XModel **attachWorldModel;					//Count = 8
  const char **attachViewModelTag;				//Count = 8
  const char **attachWorldModelTag;				//Count = 8
  vec3_t attachViewModelOffset[8];
  vec3_t attachWorldModelOffset[8];
  vec3_t attachViewModelRotation[8];
  vec3_t attachWorldModelRotation[8];
  vec3_t stowedModelOffsets;
  vec3_t stowedModelRotations;
  unsigned int altWeaponIndex;
  int iAttachments;
  bool bIgnoreAttachments;
  int iClipSize;
  int iReloadTime;
  int iReloadEmptyTime;
  int iReloadQuickTime;
  int iReloadQuickEmptyTime;
  int iAdsTransInTime;
  int iAdsTransOutTime;
  int iAltRaiseTime;
  const char *szAmmoDisplayName;
  const char *szAmmoName;
  int iAmmoIndex;
  const char *szClipName;
  int iClipIndex;
  float fAimAssistRangeAds;
  float fAdsSwayHorizScale;
  float fAdsSwayVertScale;
  float fAdsViewKickCenterSpeed;
  float fHipViewKickCenterSpeed;
  float fAdsZoomFov[3];
  float fAdsZoomInFrac;
  float fAdsZoomOutFrac;
  float fOverlayAlphaScale;
  float fOOPosAnimLength[2];
  bool bSilenced;
  bool bDualMag;
  bool bInfraRed;
  bool bTVGuided;
  unsigned int perks[2];
  bool bAntiQuickScope;
  Material *overlayMaterial;
  Material *overlayMaterialLowRes;
  Material *dpadIcon;
  weaponIconRatioType_t dpadIconRatio;
  bool noAmmoOnDpadIcon;
  bool mmsWeapon;
  bool mmsInScope;
  float mmsFOV;
  float mmsAspect;
  float mmsMaxDist;
  vec3_t ikLeftHandIdlePos;
  vec3_t ikLeftHandOffset;
  vec3_t ikLeftHandRotation;
  bool bUsingLeftHandProneIK;
  vec3_t ikLeftHandProneOffset;
  vec3_t ikLeftHandProneRotation;
  vec3_t ikLeftHandUiViewerOffset;
  vec3_t ikLeftHandUiViewerRotation;

  int dumpWeaponVariantDef();
};

typedef void (__cdecl * Load_WeaponVariantDefAsset_t)(WeaponVariantDef **weaponVariantDef);
extern Load_WeaponVariantDefAsset_t Load_WeaponVariantDefAsset;
void Load_WeaponVariantDefAssetSaveStub(WeaponVariantDef ** input);
void Load_WeaponVariantDefAssetHook(WeaponVariantDef ** input);
#pragma endregion

#pragma region attachment (0x1E)
enum eAttachment
{
  ATTACHMENT_NONE = 0x0,
  ATTACHMENT_ACOG = 0x1,
  ATTACHMENT_DUALCLIP = 0x2,
  ATTACHMENT_DUALOPTIC = 0x3,
  ATTACHMENT_DW = 0x4,
  ATTACHMENT_EXTBARREL = 0x5,
  ATTACHMENT_EXTCLIP = 0x6,
  ATTACHMENT_EXTRAMAGS = 0x7,
  ATTACHMENT_FASTADS = 0x8,
  ATTACHMENT_FASTRELOAD = 0x9,
  ATTACHMENT_FMJ = 0xA,
  ATTACHMENT_GL = 0xB,
  ATTACHMENT_GRIP = 0xC,
  ATTACHMENT_HOLO = 0xD,
  ATTACHMENT_IR = 0xE,
  ATTACHMENT_IRONSIGHTS = 0xF,
  ATTACHMENT_LONGBREATH = 0x10,
  ATTACHMENT_MK = 0x11,
  ATTACHMENT_MMS = 0x12,
  ATTACHMENT_RANGEFINDER = 0x13,
  ATTACHMENT_REFLEX = 0x14,
  ATTACHMENT_RF = 0x15,
  ATTACHMENT_SELECTFIRE = 0x16,
  ATTACHMENT_SILENCER = 0x17,
  ATTACHMENT_STACKFIRE = 0x18,
  ATTACHMENT_STALKER = 0x19,
  ATTACHMENT_STEADYAIM = 0x1A,
  ATTACHMENT_SWAYREDUC = 0x1B,
  ATTACHMENT_TACKNIFE = 0x1C,
  ATTACHMENT_VZOOM = 0x1D,
  ATTACHMENT_TYPE_COUNT = 0x1E,
  ATTACHMENT_INVALID = 0x1E
};
 
enum eAttachmentPoint
{
  ATTACHMENT_POINT_NONE = 0x0,
  ATTACHMENT_POINT_TOP = 0x1,
  ATTACHMENT_POINT_FIRST = 0x1,
  ATTACHMENT_POINT_BOTTOM = 0x2,
  ATTACHMENT_POINT_TRIGGER = 0x3,
  ATTACHMENT_POINT_MUZZLE = 0x4,
  ATTACHMENT_POINT_GUNPERK = 0x5,
  ATTACHMENT_POINT_COUNT = 0x6,
  ATTACHMENT_POINT_INVALID = 0x6
};
 
struct WeaponAttachment
{
  const char * name;
  const char * szDisplayName;
  eAttachment attachmentType;
  eAttachmentPoint attachmentPoint;
  PenetrateType penetrateType;
  weapFireType_t fireType;
  int firstRaisePriority;
  float fHipIdleAmount;
  bool bAltWeaponAdsOnly;
  bool bAltWeaponDisableSwitching;
  int altScopeADSTransInTime;
  int altScopeADSTransOutTime;
  bool bSilenced;
  bool bDualMag;
  bool laserSight;
  bool bInfraRed;
  bool bUseAsMelee;
  bool bDualWield;
  bool sharedAmmo;
  float fDamageRangeScale;
  float fAdsZoomFov[3];
  float fAdsZoomInFrac;
  float fAdsZoomOutFrac;
  float fAdsTransInTimeScale;
  float fAdsTransOutTimeScale;
  float fAdsRecoilReductionRate;
  float fAdsRecoilReductionLimit;
  float fAdsViewKickCenterSpeedScale;
  float fAdsIdleAmountScale;
  bool swayOverride;
  float swayMaxAngle;
  float swayLerpSpeed;
  float swayPitchScale;
  float swayYawScale;
  float swayHorizScale;
  float swayVertScale;
  bool adsSwayOverride;
  float adsSwayMaxAngle;
  float adsSwayLerpSpeed;
  float adsSwayPitchScale;
  float adsSwayYawScale;
  float fAdsSwayHorizScale;
  float fAdsSwayVertScale;
  float adsMoveSpeedScale;
  float fHipSpreadMinScale;
  float fHipSpreadMaxScale;
  float strafeRotR;
  float standMoveF;
  vec3_t vStandRot;
  float fFireTimeScale;
  float fReloadTimeScale;
  float fReloadEmptyTimeScale;
  float fReloadAddTimeScale;
  float fReloadQuickTimeScale;
  float fReloadQuickEmptyTimeScale;
  float fReloadQuickAddTimeScale;
  bool mmsWeapon;
  bool mmsInScope;
  float mmsFOV;
  float mmsAspect;
  float mmsMaxDist;
  float clipSizeScale;
  int iClipSize;
  unsigned int stackFire;
  float stackFireSpread;
  float stackFireAccuracyDecay;
  unsigned int perks[2];
  float customFloat[3];
  int customBool[3];

  int dumpWeaponAttachment();
};

typedef void (__cdecl * Load_WeaponAttachmentAsset_t)(WeaponAttachment **weaponAttachment);
extern Load_WeaponAttachmentAsset_t Load_WeaponAttachmentAsset;
void Load_WeaponAttachmentAssetSaveStub(WeaponAttachment ** input);
void Load_WeaponAttachmentAssetHook(WeaponAttachment ** input);
#pragma endregion

#pragma region attachmentunique (0x1F)
struct WeaponAttachmentUnique
{
  const char *szInternalName;
  eAttachment attachmentType;
  int siblingLink;
  int childLink;
  int combinedAttachmentTypeMask;
  const char *szAltWeaponName;
  unsigned int altWeaponIndex;
  const char *szDualWieldWeaponName;
  unsigned int dualWieldWeaponIndex;
  ScriptString *hideTags;
  XModel * viewModel;
  XModel * viewModelAdditional;
  XModel * viewModelADS;
  XModel * worldModel;
  XModel * worldModelAdditional;
  char * viewModelTag;
  char * worldModelTag;
  vec3_t viewModelOffsets;
  vec3_t worldModelOffsets;
  vec3_t viewModelRotations;
  vec3_t worldModelRotations;
  vec3_t viewModelAddOffsets;
  vec3_t worldModelAddOffsets;
  vec3_t viewModelAddRotations;
  vec3_t worldModelAddRotations;
  WeaponCamo *weaponCamo;
  bool disableBaseWeaponAttachment;
  bool disableBaseWeaponClip;
  bool overrideBaseWeaponAttachmentOffsets;
  vec3_t viewModelOffsetBaseAttachment;
  vec3_t worldModelOffsetBaseAttachment;
  Material *overlayMaterial;
  Material *overlayMaterialLowRes;
  weapOverlayReticle_t overlayReticle;
  int iFirstRaiseTime;
  int iAltRaiseTime;
  int iAltDropTime;
  int iReloadAmmoAdd;
  int iReloadStartAdd;
  bool bSegmentedReload;
  const char **szXAnims;        //Count = 0x58
  int animationOverrides[3];
  float (* locationDamageMultipliers)[21];  //21
  int soundOverrides;
  const char *fireSound;
  const char *fireSoundPlayer;
  const char *fireLoopSound;
  const char *fireLoopSoundPlayer;
  const char *fireLoopEndSound;
  const char *fireLoopEndSoundPlayer;
  const char *fireStartSound;
  const char *fireStopSound;
  const char *fireStartSoundPlayer;
  const char *fireStopSoundPlayer;
  const char *fireLastSound;
  const char *fireLastSoundPlayer;
  const char *fireKillcamSound;
  const char *fireKillcamSoundPlayer;
  int effectOverrides;
  FxEffectDef * viewFlashEffect;
  FxEffectDef * worldFlashEffect;
  TracerDef *tracerType;
  TracerDef *enemyTracerType;
  float adsDofStart;
  float adsDofEnd;
  int iAmmoIndex;
  int iClipIndex;
  bool bOverrideLeftHandIK;
  bool bOverrideLeftHandProneIK;
  vec3_t ikLeftHandOffset;
  vec3_t ikLeftHandRotation;
  vec3_t ikLeftHandProneOffset;
  vec3_t ikLeftHandProneRotation;
  float customFloat[3];
  int customBool[3];
  
  int dumpWeaponAttachmentUnique();
};

typedef void (__cdecl * Load_WeaponAttachmentUniqueAsset_t)(WeaponAttachmentUnique **weaponAttachmentUnique);
extern Load_WeaponAttachmentUniqueAsset_t Load_WeaponAttachmentUniqueAsset;
void Load_WeaponAttachmentUniqueAssetSaveStub(WeaponAttachmentUnique ** input);
void Load_WeaponAttachmentUniqueAssetHook(WeaponAttachmentUnique ** input);
#pragma endregion

#pragma region fx (0x22)
struct FxSpawnDefLooping
{
  int intervalMsec;
  int count;
};

struct FxIntRange
{
  int base;
  int amplitude;
};

struct FxSpawnDefOneShot
{
  FxIntRange count;
};

union FxSpawnDef
{
  FxSpawnDefLooping looping;
  FxSpawnDefOneShot oneShot;
};

struct FxFloatRange
{
  float base;
  float amplitude;
};

struct FxElemAtlas
{
  char behavior;
  char index;
  char fps;
  char loopCount;
  char colIndexBits;
  char rowIndexBits;
  unsigned __int16 entryCountAndIndexRange;
};

struct FxElemVec3Range
{
  vec3_t base;
  vec3_t amplitude;
};

struct FxElemVelStateInFrame
{
  FxElemVec3Range velocity;
  FxElemVec3Range totalDelta;
};

const struct FxElemVelStateSample
{
  FxElemVelStateInFrame local;
  FxElemVelStateInFrame world;
};

struct FxElemVisualState
{
  char color[4];
  float rotationDelta;
  float rotationTotal;
  float size[2];
  float scale;
};

const struct FxElemVisStateSample
{
  FxElemVisualState base;
  FxElemVisualState amplitude;
};

struct FxElemMarkVisuals
{
  Material *materials[2];
};

union FxEffectDefRef
{
  FxEffectDef *handle;
  const char *name;
};

union FxElemVisuals
{
  const void *anonymous;
  Material *material;
  XModel *model;
  FxEffectDefRef effectDef;
  const char *soundName;
  GfxLightDef *lightDef;
};

union FxElemDefVisuals
{
  FxElemMarkVisuals *markArray;
  FxElemVisuals *array;
  FxElemVisuals instance;
};

struct FxTrailVertex
{
  vec2_t pos;
  vec2_t normal;
  float texCoord;
};

struct FxTrailDef
{
  int scrollTimeMsec;
  int repeatDist;
  int splitDist;
  int vertCount;
  union {
	  FxTrailVertex *vertsEA;
	  FxTrailVertex *verts;
  };
  int indCount;
  union {
	  unsigned __int16 *indsEA;
	  unsigned __int16 *inds;
  };
};

struct FxSpotLightDef
{
  float fovInnerFraction;
  float startRadius;
  float endRadius;
};

union FxElemExtendedDefPtr
{
  FxTrailDef *localTrailDef;
  FxTrailDef *trailDef;
  FxSpotLightDef *localSpotLightDef;
  FxSpotLightDef *spotLightDef;
  void *unknownDef;
};

struct FxBillboardTrim
{
  float topWidth;
  float bottomWidth;
};

union FxElemDefUnion
{
  FxBillboardTrim billboard;
  FxIntRange cloudDensityRange;
};

struct FxElemSpawnSound
{
  const char *spawnSound;
};

const struct FxElemDef
{
  int flags;
  FxSpawnDef spawn;
  FxFloatRange spawnRange;
  FxFloatRange fadeInRange;
  FxFloatRange fadeOutRange;
  float spawnFrustumCullRadius;
  FxIntRange spawnDelayMsec;
  FxIntRange lifeSpanMsec;
  FxFloatRange spawnOrigin[3];
  FxFloatRange spawnOffsetRadius;
  FxFloatRange spawnOffsetHeight;
  FxFloatRange spawnAngles[3];
  FxFloatRange angularVelocity[3];
  FxFloatRange initialRotation;
  unsigned int rotationAxis;
  FxFloatRange gravity;
  FxFloatRange reflectionFactor;
  FxElemAtlas atlas;
  float windInfluence;
  char elemType;
  char visualCount;
  char velIntervalCount;
  char visStateIntervalCount;
  FxElemVelStateSample *velSamples;
  FxElemVisStateSample *visSamples;
  FxElemDefVisuals visuals;
  vec3_t collMins;
  vec3_t collMaxs;
  FxEffectDefRef effectOnImpact;
  FxEffectDefRef effectOnDeath;
  FxEffectDefRef effectEmitted;
  FxFloatRange emitDist;
  FxFloatRange emitDistVariance;
  FxEffectDefRef effectAttached;
  FxElemExtendedDefPtr extended;
  char sortOrder;
  char lightingFrac;
  unsigned __int16 alphaFadeTimeMsec;
  unsigned __int16 maxWindStrength;
  unsigned __int16 spawnIntervalAtMaxWind;
  unsigned __int16 lifespanAtMaxWind;
  FxElemDefUnion u;
  FxElemSpawnSound spawnSound;
  vec2_t billboardPivot;
};

const struct FxEffectDef
{
  const char *name;
  unsigned __int16 flags;
  char efPriority;
  __int16 elemDefCountLooping;
  __int16 elemDefCountOneShot;
  __int16 elemDefCountEmission;
  int totalSize;
  int msecLoopingLife;
  int msecNonLoopingLife;
  union {
    FxElemDef *elemDefs;
    FxElemDef *localElemDefs;
  };
  vec3_t boundingBoxDim;
  vec3_t boundingBoxCentre;
  float occlusionQueryDepthBias;
  int occlusionQueryFadeIn;
  int occlusionQueryFadeOut;
  FxFloatRange occlusionQueryScaleRange;
};
#pragma endregion

#pragma region rawfile (0x2A)
struct RawFile
{
  const char *name;
  int len;
  const char *buffer;

  int dumpRawfile();
};

typedef void (__cdecl * Load_RawFileAsset_t)(RawFile **rawFile);
extern Load_RawFileAsset_t Load_RawFileAsset;
void Load_RawFileAssetSaveStub(RawFile ** input);
void Load_RawFileAssetHook(RawFile ** input);
#pragma endregion

#pragma region stringtable (0x2B)
struct StringTableCell
{
  const char *string;
  int hash;
};

struct StringTable
{
  const char *name;
  int columnCount;
  int rowCount;
  StringTableCell *values;
  __int16 *cellIndex;

  int dumpStringTable();
};

typedef void (__cdecl * Load_StringTableAsset_t)(StringTable **stringTable);
extern Load_StringTableAsset_t Load_StringTableAsset;
void Load_StringTableAssetSaveStub(StringTable ** input);
void Load_StringTableAssetHook(StringTable ** input);

// we don't like Boost
#define strtk_no_tr1_or_boost

// conflicting windows.h definitions
#undef max
#undef min

// strtk code
#include "strtk\strtk.hpp"
#define  _XOPEN_SOURCE_EXTENDED 1
#include <string>
extern strtk::token_grid::options strtkGridOptions;
#pragma endregion

#pragma region ddl (0x2E)
enum ddlPrimitiveTypes_e : unsigned int
{
  DDL_INVALID_TYPE = 0xFFFFFFFF,
  DDL_BYTE_TYPE = 0x0,
  DDL_SHORT_TYPE = 0x1,
  DDL_UINT_TYPE = 0x2,
  DDL_INT_TYPE = 0x3,
  DDL_INT64_TYPE = 0x4,
  DDL_FLOAT_TYPE = 0x5,
  DDL_FIXEDPOINT_TYPE = 0x6,
  DDL_STRING_TYPE = 0x7,
  DDL_STRUCT_TYPE = 0x8,
  DDL_ENUM_TYPE = 0x9
};
 
struct ddlHash_t
{
  int hash;
  int index;
};
 
struct ddlEnumDef_t
{
  const char *name;
  int memberCount;
  const char **members;
  ddlHash_t *hashTable;
};
 
struct ddlMemberDef_t
{
  const char *name;
  int size;
  int offset;
  ddlPrimitiveTypes_e type;
  int externalIndex;
  unsigned int rangeLimit;
  unsigned int serverDelta;
  unsigned int clientDelta;
  int arraySize;
  int enumIndex;
  int permission;
};
 
struct ddlStructDef_t
{
  const char *name;
  int size;
  int memberCount;
  ddlMemberDef_t *members;
  ddlHash_t *hashTable;
};
 
struct ddlDef_t
{
  int version;
  int size;
  ddlStructDef_t *structList;
  int structCount;
  ddlEnumDef_t *enumList;
  int enumCount;
  ddlDef_t *next;
};
 
struct ddlRoot_t
{
  const char *name;
  ddlDef_t *ddlDef;

  int Dump_ddlRoot_t();
};

typedef void (__cdecl * Load_ddlRoot_tAsset_t)(StringTable **stringTable);
extern Load_ddlRoot_tAsset_t Load_ddlRoot_tAsset;
void Load_ddlRoot_tAssetSaveStub(ddlRoot_t ** input);
void Load_ddlRoot_tAssetHook(ddlRoot_t ** input);
#pragma endregion

#pragma region scriptparsetree (0x32)
struct GSC_OBJ
{
  char magic[8];
  unsigned int source_crc;
  unsigned int include_offset;
  unsigned int animtree_offset;
  unsigned int cseg_offset;
  unsigned int stringtablefixup_offset;
  unsigned int exports_offset;
  unsigned int imports_offset;
  unsigned int fixup_offset;
  unsigned int profile_offset;
  unsigned int cseg_size;
  unsigned __int16 name;
  unsigned __int16 stringtablefixup_count;
  unsigned __int16 exports_count;
  unsigned __int16 imports_count;
  unsigned __int16 fixup_count;
  unsigned __int16 profile_count;
  char include_count;
  char animtree_count;
  char flags;
};

struct GSC_IMPORT_ITEM
{
  unsigned __int16 name;
  unsigned __int16 name_space;
  unsigned __int16 num_address;
  char param_count;
  char flags;
};

struct ScriptParseTree
{
  const char *name;
  int len;
  char *buffer;

  int dumpScriptParseTree();
};

enum scriptInstance_t
{
  SCRIPTINSTANCE_SERVER = 0x0,
  SCRIPTINSTANCE_CLIENT = 0x1,
  SCRIPT_INSTANCE_MAX = 0x2
};

typedef void (__cdecl * Load_ScriptParseTreeAsset_t)(ScriptParseTree **scriptParseTree);
extern Load_ScriptParseTreeAsset_t Load_ScriptParseTreeAsset;
int Scr_ResolveScriptFunctionHook(scriptInstance_t inst, GSC_OBJ *prime_obj, GSC_IMPORT_ITEM *import, char op, bool is_pushfunc);
void Load_ScriptParseTreeAssetSaveStub(ScriptParseTree ** input);
void Load_ScriptParseTreeAssetHook(ScriptParseTree ** input);

void Scr_GetGSCObjHook(scriptInstance_t inst, const char *name, bool appendExtension, bool errorIfMissing);
void Scr_GetGSCObjSaveStub(scriptInstance_t inst, const char *name, bool appendExtension, bool errorIfMissing);
void Scr_LoadScriptInternalHook(scriptInstance_t inst, const char *filename);
void Scr_LoadScriptInternalSaveStub(scriptInstance_t inst, const char *filename);

typedef int (__cdecl * Scr_ResolveScriptFunction_t)(scriptInstance_t inst, GSC_OBJ *prime_obj, GSC_IMPORT_ITEM *import, char op, bool is_pushfunc);
extern Scr_ResolveScriptFunction_t Scr_ResolveScriptFunction;

extern XAssetPool<ScriptParseTree, 0x400> * g_scriptParseTreePool;
#pragma endregion

#pragma region vehicle (0x34)
enum VehicleTypes : short
{
  VEH_WHEELS_4 = 0x0,
  VEH_MOTORCYCLE = 0x1,
  VEH_TANK = 0x2,
  VEH_PLANE = 0x3,
  VEH_BOAT = 0x4,
  VEH_ARTILLERY = 0x5,
  VEH_HELICOPTER = 0x6,
  NUM_VEHICLE_TYPES = 0x7,
};
 
enum EVehicleCameraMode : short
{
  VEH_MODE_FIRSTPERSON = 0x0,
  VEH_MODE_CHASECAM = 0x1,
  VEH_MODE_HLO = 0x2,
  VEH_MODE_STRAFE = 0x3,
  VEH_MODE_HORSE = 0x4,
  VEH_MODE_OLDTANK = 0x5,
  VEH_MODE_HOVER = 0x6,
  VEH_MODE_VTOL = 0x7,
  VEH_MODE_MAX = 0x8
};
 
enum TractionType : int
{
  TRACTION_TYPE_FRONT = 0,
  TRACTION_TYPE_BACK = 1,
  TRACTION_TYPE_ALL_WD = 2,
  NUM_TRACTION_TYPES
};

enum DevEventType
{
  EVENT_ACTIVATE = 0x0,
  EVENT_DEACTIVATE = 0x1,
  EVENT_ACCEPT = 0x2,
  EVENT_UPDATE = 0x3,
  EVENT_DRAW = 0x4,
  EVENT_SAVE = 0x5
};
 
struct view_limits_t
{
  float horizSpanLeft;
  float horizSpanRight;
  float vertSpanUp;
  float vertSpanDown;
  float horizResistLeft;
  float horizResistRight;
  float vertResistUp;
  float vertResistDown;
};
 
struct DevGraph
{
  vec2_t *knots;
  int *knotCount;
  int knotCountMax;
  int selectedKnot;
  void (__cdecl *eventCallback)(DevGraph *, DevEventType, LocalClientNum_t);
  void (__cdecl *textCallback)(DevGraph *, const float, const float, char *, const int);
  void *data;
  bool disableEditingEndPoints;
};
 
//This is unused in the FF files, and acts as a sort of buffer in memory.
struct GraphFloat
{
  char name[64];
  vec2_t knots[32];
  int knotCount;
  float scale;
  DevGraph devguiGraph;
};
 
struct VehicleParameter
{
  float m_speed_max;
  float m_accel_max;
  float m_reverse_scale;
  float m_steer_angle_max;
  float m_steer_angle_speed_scale;
  float m_steer_speed;
  float m_wheel_radius;
  float m_susp_spring_k;
  float m_susp_damp_k;
  float m_susp_adj;
  float m_susp_hard_limit;
  float m_susp_min_height;
  float m_tire_fric_fwd;
  float m_tire_fric_side;
  float m_tire_fric_brake;
  float m_tire_fric_hand_brake;
  float m_body_mass;
  float m_roll_stability;
  float m_pitch_stability;
  float m_pitch_roll_resistance;
  float m_yaw_resistance;
  float m_upright_strength;
  float m_tilt_fakey;
  float m_peel_out_max_speed;
  float m_tire_damp_coast;
  float m_tire_damp_brake;
  float m_tire_damp_hand;
  float m_auto_hand_brake_min_speed;
  TractionType m_traction_type;
  const char *m_name;
  vec3_t m_bbox_min;
  vec3_t m_bbox_max;
  vec3_t m_mass_center_offset;
  vec3_t m_buoyancybox_min;
  vec3_t m_buoyancybox_max;
  float m_water_speed_max;
  float m_water_accel_max;
  float m_water_turn_accel;
  float m_water_turn_speed_max;
  float m_water_ebrake_power;
  vec3_t m_boat_motor_offset;
  float m_boat_speed_rise;
  float m_boat_speed_tilt;
  float m_boat_side_fric_scale;
  float m_boat_forward_fric_scale;
  float m_boat_vertical_fric_scale;
  float m_jump_force;
  float m_tire_fric_side_max;
  bool m_drive_on_walls;
  float m_linear_drag_scale;
  float m_angular_drag_scale;
};
 
struct VehicleDriveBySound
{
  int apex;
  const char *name;
  unsigned int alias;
};
 
struct VehicleEngineSound
{
  const char *name;
  unsigned int alias;
  float params[5];
};
 
struct VehicleGearData
{
  float minRPM;
  float maxRPM;
  float ratio;
};
 
struct VehicleEngine
{
  float idleRpms;
  float maxRpms;
  float maxTorque;
  float brakingCoeff;
  float onLoadFadeInStart;
  float onLoadFadeInEnd;
  float offLoadFadeOutStart;
  float offLoadFadeOutEnd;
  float loadScale;
  float loadSmoothing;
  float throttleLag;
  float pitchScale;
  VehicleEngineSound onload[5];
  VehicleEngineSound offload[5];
  int numGears;
  int loopLastGear;
  VehicleGearData gears[10];
};
 
struct VehicleAntenna
{
  float springK;
  float damp;
  float length;
  float gravity;
};
 
struct VehicleDef
{
  const char * name;
  VehicleTypes type;
  int remoteControl;
  int bulletDamage;
  int armorPiercingDamage;
  int grenadeDamage;
  int projectileDamage;
  int projectileSplashDamage;
  int heavyExplosiveDamage;
  EVehicleCameraMode cameraMode;
  int autoRecenterOnAccel;
  int thirdPersonDriver;
  int thirdPersonUseVehicleRoll;
  int thirdPersonCameraPitchVehicleRelative;
  int thirdPersonCameraHeightWorldRelative;
  float thirdPersonCameraRange;
  float thirdPersonCameraMinPitchClamp;
  float thirdPersonCameraMaxPitchClamp;
  float thirdPersonCameraHeight[2];
  float thirdPersonCameraPitch[2];
  int cameraAlwaysAutoCenter;
  float cameraAutoCenterLerpRate;
  float cameraAutoCenterMaxLerpRate;
  float thirdPersonCameraSpringDistance;
  float thirdPersonCameraSpringTime;
  float thirdPersonCameraHandbrakeTurnRateInc;
  float cameraFOV;
  float cameraRollFraction;
  vec3_t tagPlayerOffset;
  int killcamCollision;
  float killcamDist;
  float killcamZDist;
  float killcamMinDist;
  float killcamZTargetOffset;
  float killcamFOV;
  float killcamNearBlur;
  float killcamNearBlurStart;
  float killcamNearBlurEnd;
  float killcamFarBlur;
  float killcamFarBlurStart;
  float killcamFarBlurEnd;
  int isDrivable;
  int numberOfSeats;
  int numberOfGunners;
  int seatSwitchOrder[11];
  int driverControlledGunPos;
  float enterRadiusDriver;
  float enterRadiusGunner[4];
  float texureScrollScale;
  float wheelRotRate;
  float extraWheelRotScale;
  int wheelChildTakesSteerYaw;
  float maxSpeed;
  float maxSpeedVertical;
  float accel;
  float accelVertical;
  float rotRate;
  float rotAccel;
  float maxBodyPitch;
  float maxBodyRoll;
  float collisionDamage;
  float collisionSpeed;
  float suspensionTravel;
  float heliCollisionScalar;
  float viewPitchOffset;
  float viewInfluence;
  float tiltFromAccelerationPitch;
  float tiltFromAccelerationRoll;
  float tiltFromDecelerationPitch;
  float tiltFromDecelerationRoll;
  float tiltFromVelocityPitch;
  float tiltFromVelocityRoll;
  float tiltSpeedPitch;
  float tiltSpeedRoll;
  const char * turretWeapon;
  view_limits_t turretViewLimits;
  float turretRotRate;
  int turretClampPlayerView;
  int turretLockTurretToPlayerView;
  const char * gunnerWeapon[4];
  unsigned __int16 gunnerWeaponIndex[4];
  float gunnerRotRate;
  vec2_t gunnerRestAngles[4];
  view_limits_t passengerViewLimits[6];
  const char * turretSpinSndName;
  const char * turretStopSndName;
  unsigned int turretSpinSndIndex;
  unsigned int turretStopSndIndex;
  const char * wheelRoadNoiseSnd;
  const char * wheelSlidingSnd;
  const char * wheelPeelingOutSnd;
  float skidSpeedMin;
  float skidSpeedMax;
  const char *futzName;
  float futzBlend;
  int animType;
  const char *animSet;
  int scriptedAnimationEntry;
  float mantleAngleFront;
  float mantleAngleBack;
  float mantleAngleLeft;
  float mantleAngleRight;
  ScriptString extraWheelLeft1;
  ScriptString extraWheelRight1;
  ScriptString extraWheelLeft2;
  ScriptString extraWheelRight2;
  ScriptString driverHideTag;
  XModel * attachmentModels[4];
  ScriptString attachmentTags[4];
  XModel * deathAttachmentModels[4];
  ScriptString deathAttachmentTags[4];
  float tracerOffsetForward;
  float tracerOffsetUp;
  XModel * model;
  XModel * viewModel;
  XModel * deathModel;
  XModel * enemyModel;
  float modelSwapDelay;
  FxEffectDef * exhaustFx;
  int oneExhaust;
  FxEffectDef *treadFx[32]; //See surfaceNames_t for the names of these.
  FxEffectDef *deathFx;
  ScriptString deathFxTag;
  const char * deathFxSound;
  FxEffectDef * lightFxName[4];
  ScriptString lightFxTag[4];
  FxEffectDef * friendlyLightFx;
  ScriptString friendlyLightFxTag;
  FxEffectDef * enemyLightFx;
  ScriptString enemyLightFxTag;
  float radiusDamageMin;
  float radiusDamageMax;
  float radiusDamageRadius;
  const char *shootShock;
  const char *shootRumble;
  float deathQuakeScale;
  float deathQuakeDuration;
  float deathQuakeRadius;
  const char *rumbleType;
  float rumbleScale;
  float rumbleDuration;
  float rumbleRadius;
  float rumbleBaseTime;
  float rumbleAdditionalTime;
  int healthDefault;
  int healthMin;
  int healthMax;
  int eTeam;
  int boostAccelMultiplier;
  float boostDuration;
  float boostSpeedIncrease;
  int addToCompass;
  int addToCompassEnemy;
  const char *compassIcon;
  Material *compassIconMaterial;
  const char *gasButtonName;
  int gasButton;
  const char *reverseBrakeButtonName;
  int reverseBrakeButton;
  const char *handBrakeButtonName;
  int handBrakeButton;
  const char *attackButtonName;
  int attackButton;
  const char *attackSecondaryButtonName;
  int attackSecondaryButton;
  const char *boostButtonName;
  int boostButton;
  const char *moveUpButtonName;
  int moveUpButton;
  const char *moveDownButtonName;
  int moveDownButton;
  const char *switchSeatButtonName;
  int switchSeatButton;
  const char *steerGraphName;
  GraphFloat *steerGraph;
  const char *accelGraphName;
  GraphFloat *accelGraph;
  int isNitrous;
  int isFourWheelSteering;
  int useCollmap;
  float radius;
  float minHeight;
  float maxHeight;
  float max_fric_tilt_angle;
  float max_fric_tilt;
  int noDirectionalDamage;
  int fakeBodyStabilizer;
  float vehHelicopterBoundsRadius;
  float vehHelicopterDecelerationFwd;
  float vehHelicopterDecelerationSide;
  float vehHelicopterDecelerationUp;
  float vehHelicopterTiltFromControllerAxes;
  float vehHelicopterTiltFromFwdAndYaw;
  float vehHelicopterTiltFromFwdAndYaw_VelAtMaxTilt;
  float vehHelicopterTiltMomentum;
  int vehHelicopterQuadRotor;
  int vehHelicopterAccelTwardsView;
  float maxRotorArmMovementAngle;
  float maxRotorArmRotationAngle;
  int vehHelicopterMaintainHeight;
  int vehHelicopterMaintainMaxHeight;
  float vehHelicopterMaintainHeightLimit;
  float vehHelicopterMaintainHeightAccel;
  float vehHelicopterMaintainHeightMinimum;
  float vehHelicopterMaintainHeightMaximum;
  float vehHelicopterMaintainCeilingMinimum;
  int joltVehicle;
  int joltVehicleDriver;
  float joltMaxTime;
  float joltTime;
  float joltWaves;
  float joltIntensity;
  VehicleParameter nitrousVehParams;
  float p_driveby_sound_radius;
  float s_driveby_sound_radius;
  VehicleDriveBySound p[20];
  VehicleDriveBySound s[20];
  int doFootSteps;
  int isSentient;
  VehicleEngine engine;
  VehicleAntenna antenna[2];
  char *csvInclude;
  float customFloat[3];
  int customBool[3];

  int dumpVehicleDef();
};

typedef void (__cdecl * Load_VehicleDefAsset_t)(VehicleDef **vehicleDef);
extern Load_VehicleDefAsset_t Load_VehicleDefAsset;
extern AssetEntry VehicleDefEntries[];
void Load_VehicleDefAssetSaveStub(VehicleDef ** input);
void Load_VehicleDefAssetHook(VehicleDef ** input);
#pragma endregion

#pragma region tracer (0x37)
enum tracerType_t
{
  TRACERTYPE_LASER = 0x0,
  TRACERTYPE_SMOKE = 0x1,
  TRACERTYPE_NUM = 0x2
};
 
struct TracerDef
{
  const char *name;
  tracerType_t type;
  Material *material;
  unsigned int drawInterval;
  float speed;
  float beamLength;
  float beamWidth;
  float screwRadius;
  float screwDist;
  float fadeTime;
  float fadeScale;
  float texRepeatRate;
  vec4_t colors[5];

  int dumpTracerDef();
};

typedef void (__cdecl * Load_TracerDefAsset_t)(TracerDef **tracerDef);
extern Load_TracerDefAsset_t Load_TracerDefAsset;
extern AssetEntry TracerDefEntries[];
void Load_TracerDefAssetSaveStub(TracerDef ** input);
void Load_TracerDefAssetHook(TracerDef ** input);
#pragma endregion

#pragma region qdb (0x39)
struct Qdb
{
  const char *name;
  int len;
  char *buffer;

  int dumpQdb();
};

typedef void (__cdecl * Load_QdbAsset_t)(Qdb **qdb);
extern Load_QdbAsset_t Load_QdbAsset;
void Load_QdbAssetSaveStub(Qdb ** input);
void Load_QdbAssetHook(Qdb ** input);
#pragma endregion

#pragma region slug (0x3A)
struct Slug
{
  const char *name;
  int len;
  char *buffer;

  int dumpSlug();
};

typedef void (__cdecl * Load_SlugAsset_t)(Slug **slug);
extern Load_SlugAsset_t Load_SlugAsset;
void Load_SlugAssetSaveStub(Slug ** input);
void Load_SlugAssetHook(Slug ** input);
#pragma endregion

#pragma region footstepfxtable (0x3B)
struct FootstepTableDef
{
  const char *name;
  unsigned int sndAliasTable[32][7];

  int dumpFootstepTableDef();
};

typedef void (__cdecl * Load_FootstepTableDefAsset_t)(FootstepTableDef **footstepTableDef);
extern Load_FootstepTableDefAsset_t Load_FootstepTableDefAsset;
void Load_FootstepTableDefAssetSaveStub(FootstepTableDef ** input);
void Load_FootstepTableDefAssetHook(FootstepTableDef ** input);
#pragma endregion

#pragma region footstepfxtable (0x3C)
struct FootstepFXTableDef
{
  const char *name;
  FxEffectDef *footstepFX[0x20];

  int dumpFootstepFXTableDef();
};

typedef void (__cdecl * Load_FootstepFXTableDefAsset_t)(FootstepFXTableDef **footstepFxTableDef);
extern Load_FootstepFXTableDefAsset_t Load_FootstepFXTableDefAsset;
void Load_FootstepFXTableDefAssetSaveStub(FootstepFXTableDef ** input);
void Load_FootstepFXTableDefAssetHook(FootstepFXTableDef ** input);
#pragma endregion

#pragma region zbarrier (0x3D)
struct ZBarrierBoard
{
  XModel *pBoardModel;
  XModel *pAlternateBoardModel;
  XModel *pUpgradedBoardModel;
  const char *pTearAnim;
  const char *pBoardAnim;
  FxEffectDef * repairEffect[2];
  vec3_t repairEffectOffset[2];
  unsigned int boardRepairSound;
  unsigned int boardRepairHoverSound;
  unsigned int pauseAndRepeatRepairSound;
  float pauseBetweenRepSoundsMin;
  float pauseBetweenRepSoundsMax;
  ScriptString zombieBoardTearStateName;
  ScriptString zombieBoardTearSubStateName;
  unsigned int numRepsToPullProBoard;
};
 
struct ZBarrierDef
{
  const char *name;
  unsigned int generalRepairSound[2];
  unsigned int upgradedGeneralRepairSound[2];
  unsigned int useDelayBetweenGeneralRepSounds;
  float delayBetweenGeneralRepSounds;
  unsigned int earthquakeOnRepair;
  float earthquakeMinScale;
  float earthquakeMaxScale;
  float earthquakeMinDuration;
  float earthquakeMaxDuration;
  float earthquakeRadius;
  int numBoardsInBarrier;
  unsigned int autoHideOpenPieces;
  unsigned int taunts;
  unsigned int reachThroughAttacks;
  ScriptString zombieTauntAnimState;
  ScriptString zombieReachThroughAnimState;
  int numAttackSlots;
  float attackSpotHorzOffset;
  ZBarrierBoard boards[6];

  int dumpZBarrierDef();
};

typedef void (__cdecl * Load_ZBarrierDefAsset_t)(ZBarrierDef **tracerDef);
extern Load_ZBarrierDefAsset_t Load_ZBarrierDefAsset;
void Load_ZBarrierDefAssetSaveStub(ZBarrierDef ** input);
void Load_ZBarrierDefAssetHook(ZBarrierDef ** input);
#pragma endregion

union XAssetHeader
{
  //XModelPieces *xmodelPieces;
  PhysPreset *physPreset;
  PhysConstraints *physConstraints;
  DestructibleDef *destructibleDef;
 /* XAnimParts *parts;
  XModel *model;
  Material *material;
  MaterialPixelShader *pixelShader;
  MaterialVertexShader *vertexShader;
  MaterialTechniqueSet *techniqueSet;*/
  GfxImage *image;
  /*SndBank *sound;
  SndPatch *soundPatch;
  clipMap_t *clipMap;
  ComWorld *comWorld;
  GameWorldSp *gameWorldSp;
  GameWorldMp *gameWorldMp;*/
  MapEnts *mapEnts;
  /*GfxWorld *gfxWorld;*/
  GfxLightDef *lightDef;
  /*Font_s *font;
  FontIcon *fontIcon;
  MenuList *menuList;
  menuDef_t *menu;*/
  LocalizeEntry *localize;
  WeaponVariantDef *weapon;
  WeaponAttachment *attachment;
  WeaponAttachmentUnique *attachmentUnique;
  /*WeaponCamo *weaponCamo;
  SndDriverGlobals *sndDriverGlobals;*/
  FxEffectDef *fx;
  /*FxImpactTable *impactFx;*/
  RawFile *rawfile;
  StringTable *stringTable;
  /*LeaderboardDef *leaderboardDef;
  XGlobals *xGlobals;*/
  ddlRoot_t *ddlRoot;
  /*Glasses *glasses;
  TextureList *textureList;
  EmblemSet *emblemSet;*/
  ScriptParseTree *scriptParseTree;
  /*KeyValuePairs *keyValuePairs;*/
  VehicleDef *vehicleDef;
  /*MemoryBlock *memoryBlock;
  AddonMapEnts *addonMapEnts;*/
  TracerDef *tracerDef;
  /*SkinnedVertsDef *skinnedVertsDef;*/
  Qdb *qdb;
  Slug *slug;
  FootstepTableDef *footstepTableDef;
  FootstepFXTableDef *footstepFXTableDef;
  ZBarrierDef *zbarrierDef;
  void *data;
};

typedef XAssetHeader (__cdecl * DB_FindXAssetHeader_t)(XAssetType type, const char *name, bool errorIfMissing, int waitTime);
extern DB_FindXAssetHeader_t DB_FindXAssetHeader;

#endif//_DB_REGISTRY