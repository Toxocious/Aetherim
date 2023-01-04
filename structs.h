#pragma once
#include <cstdint>

#define ZERO_ARRAY 0

typedef struct MonitorData MonitorData;
typedef int32_t TypeIndex;
typedef int32_t TypeDefinitionIndex;
typedef int32_t FieldIndex;
typedef int32_t DefaultValueIndex;
typedef int32_t DefaultValueDataIndex;
typedef int32_t CustomAttributeIndex;
typedef int32_t ParameterIndex;
typedef int32_t MethodIndex;
typedef int32_t GenericMethodIndex;
typedef int32_t PropertyIndex;
typedef int32_t EventIndex;
typedef int32_t GenericContainerIndex;
typedef int32_t GenericParameterIndex;
typedef int16_t GenericParameterConstraintIndex;
typedef int32_t NestedTypeIndex;
typedef int32_t InterfacesIndex;
typedef int32_t VTableIndex;
typedef int32_t InterfaceOffsetIndex;
typedef int32_t RGCTXIndex;
typedef int32_t StringIndex;
typedef int32_t StringLiteralIndex;
typedef int32_t GenericInstIndex;
typedef int32_t ImageIndex;
typedef int32_t AssemblyIndex;
typedef int32_t InteropDataIndex;

typedef struct Il2CppClass Il2CppClass;
typedef struct Il2CppGuid Il2CppGuid;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppAppDomain Il2CppAppDomain;
typedef struct Il2CppAppDomainSetup Il2CppAppDomainSetup;
typedef struct Il2CppDelegate Il2CppDelegate;
typedef struct Il2CppAppContext Il2CppAppContext;
typedef struct Il2CppNameToTypeDefinitionIndexHashTable Il2CppNameToTypeDefinitionIndexHashTable;
typedef uintptr_t il2cpp_array_size_t;
typedef int32_t il2cpp_array_lower_bound_t;

typedef enum Il2CppTypeEnum
{
  IL2CPP_TYPE_END = 0x00,
  IL2CPP_TYPE_VOID = 0x01,
  IL2CPP_TYPE_BOOLEAN = 0x02,
  IL2CPP_TYPE_CHAR = 0x03,
  IL2CPP_TYPE_I1 = 0x04,
  IL2CPP_TYPE_U1 = 0x05,
  IL2CPP_TYPE_I2 = 0x06,
  IL2CPP_TYPE_U2 = 0x07,
  IL2CPP_TYPE_I4 = 0x08,
  IL2CPP_TYPE_U4 = 0x09,
  IL2CPP_TYPE_I8 = 0x0a,
  IL2CPP_TYPE_U8 = 0x0b,
  IL2CPP_TYPE_R4 = 0x0c,
  IL2CPP_TYPE_R8 = 0x0d,
  IL2CPP_TYPE_STRING = 0x0e,
  IL2CPP_TYPE_PTR = 0x0f,
  IL2CPP_TYPE_BYREF = 0x10,
  IL2CPP_TYPE_VALUETYPE = 0x11,
  IL2CPP_TYPE_CLASS = 0x12,
  IL2CPP_TYPE_VAR = 0x13,
  IL2CPP_TYPE_ARRAY = 0x14,
  IL2CPP_TYPE_GENERICINST = 0x15,
  IL2CPP_TYPE_TYPEDBYREF = 0x16,
  IL2CPP_TYPE_I = 0x18,
  IL2CPP_TYPE_U = 0x19,
  IL2CPP_TYPE_FNPTR = 0x1b,
  IL2CPP_TYPE_OBJECT = 0x1c,
  IL2CPP_TYPE_SZARRAY = 0x1d,
  IL2CPP_TYPE_MVAR = 0x1e,
  IL2CPP_TYPE_CMOD_REQD = 0x1f,
  IL2CPP_TYPE_CMOD_OPT = 0x20,
  IL2CPP_TYPE_INTERNAL = 0x21,
  IL2CPP_TYPE_MODIFIER = 0x40,
  IL2CPP_TYPE_SENTINEL = 0x41,
  IL2CPP_TYPE_PINNED = 0x45,
  IL2CPP_TYPE_ENUM = 0x55
} Il2CppTypeEnum;

struct Il2CppClass;
typedef struct PropertyInfo PropertyInfo;
typedef struct FieldInfo FieldInfo;
typedef struct EventInfo EventInfo;
struct MethodInfo;

typedef void ( *Il2CppMethodPointer )();

typedef void ( *PInvokeMarshalToNativeFunc )( void * managedStructure, void * marshaledStructure );
typedef void ( *PInvokeMarshalFromNativeFunc )( void * marshaledStructure, void * managedStructure );
typedef void ( *PInvokeMarshalCleanupFunc )( void * marshaledStructure );

typedef struct Il2CppType
{
  void * data;
  unsigned int bits;
} Il2CppType;

struct Il2CppObject
{
  Il2CppClass * klass;
  void * monitor;
};

typedef struct Il2CppIUnknown * ( *CreateCCWFunc )( Il2CppObject * obj );

typedef struct Il2CppInteropData
{
  Il2CppMethodPointer delegatePInvokeWrapperFunction;
  PInvokeMarshalToNativeFunc pinvokeMarshalToNativeFunction;
  PInvokeMarshalFromNativeFunc pinvokeMarshalFromNativeFunction;
  PInvokeMarshalCleanupFunc pinvokeMarshalCleanupFunction;
  CreateCCWFunc createCCWFunction;
  const Il2CppGuid * guid;
  const Il2CppType * type;
} Il2CppInteropData;

struct UIWidget_Fields
{
};
struct UILabel_Fields : UIWidget_Fields
{
};
struct UIBasicSprite_Fields
{
};
struct UISprite_Fields : UIBasicSprite_Fields
{
};

struct Vector2
{
  float x, y;
};

struct Vector3
{
  float x, y, z;
};

struct VirtualInvokeData
{
  Il2CppMethodPointer methodPtr;
  const MethodInfo * method;
};

typedef uint16_t Il2CppChar;

typedef struct Il2CppString
{
  Il2CppObject object;
  int32_t length;
  Il2CppChar chars[32];
} Il2CppString;

union Il2CppRGCTXData
{
  void * rgctxDataDummy;
  const MethodInfo * method;
  const Il2CppType * type;
  Il2CppClass * klass;
};

struct Il2CppRuntimeInterfaceOffsetPair
{
  Il2CppClass * interfaceType;
  int32_t offset;
};

typedef struct Il2CppAssemblyName
{
  const char * name;
  const char * culture;
  const char * hash_value;
  const char * public_key;
  uint32_t hash_alg;
  int32_t hash_len;
  uint32_t flags;
  int32_t major;
  int32_t minor;
  int32_t build;
  int32_t revision;
  uint8_t public_key_token[8];
} Il2CppAssemblyName;

typedef struct Il2CppAssembly
{
  Il2CppImage * image;
  uint32_t token;
  int32_t referencedAssemblyStart;
  int32_t referencedAssemblyCount;
  Il2CppAssemblyName aname;
} Il2CppAssembly;

typedef struct Il2CppImage
{
  const char * name;
  const char * nameNoExt;
  Il2CppAssembly * assembly;
  TypeDefinitionIndex typeStart;
  uint32_t typeCount;
  TypeDefinitionIndex exportedTypeStart;
  uint32_t exportedTypeCount;
  CustomAttributeIndex customAttributeStart;
  uint32_t customAttributeCount;
  MethodIndex entryPointIndex;
  Il2CppNameToTypeDefinitionIndexHashTable * nameToClassHashTable;
  uint32_t token;
  uint8_t dynamic;
} Il2CppImage;
typedef struct Il2CppGenericInst
{
  uint32_t type_argc;
  const Il2CppType ** type_argv;
} Il2CppGenericInst;
typedef struct Il2CppGenericContext
{
  const Il2CppGenericInst * class_inst;
  const Il2CppGenericInst * method_inst;
} Il2CppGenericContext;

typedef struct Il2CppGenericClass
{
  TypeDefinitionIndex typeDefinitionIndex;
  Il2CppGenericContext context;
  Il2CppClass * cached_class;
} Il2CppGenericClass;
typedef struct Il2CppGenericMethod
{
  const MethodInfo * methodDefinition;
  Il2CppGenericContext context;
} Il2CppGenericMethod;
typedef struct Il2CppArrayType
{
  const Il2CppType * etype;
  uint8_t rank;
  uint8_t numsizes;
  uint8_t numlobounds;
  int * sizes;
  int * lobounds;
} Il2CppArrayType;

typedef struct Il2CppTypeDefinition
{
  StringIndex nameIndex;
  StringIndex namespaceIndex;
  TypeIndex byvalTypeIndex;
  TypeIndex byrefTypeIndex;
  TypeIndex declaringTypeIndex;
  TypeIndex parentIndex;
  TypeIndex elementTypeIndex;
  RGCTXIndex rgctxStartIndex;
  int32_t rgctxCount;
  GenericContainerIndex genericContainerIndex;
  uint32_t flags;
  FieldIndex fieldStart;
  MethodIndex methodStart;
  EventIndex eventStart;
  PropertyIndex propertyStart;
  NestedTypeIndex nestedTypesStart;
  InterfacesIndex interfacesStart;
  VTableIndex vtableStart;
  InterfacesIndex interfaceOffsetsStart;
  uint16_t method_count;
  uint16_t property_count;
  uint16_t field_count;
  uint16_t event_count;
  uint16_t nested_type_count;
  uint16_t vtable_count;
  uint16_t interfaces_count;
  uint16_t interface_offsets_count;
  uint32_t bitfield;
  uint32_t token;
} Il2CppTypeDefinition;

typedef struct Il2CppClass_0
{
  const Il2CppImage * image;
  void * gc_desc;
  const char * name;
  const char * namespaze;
  Il2CppType byval_arg;
  Il2CppType this_arg;
  Il2CppClass * element_class;
  Il2CppClass * castClass;
  Il2CppClass * declaringType;
  Il2CppClass * parent;
  Il2CppGenericClass * generic_class;
  const Il2CppTypeDefinition * typeDefinition;
  const Il2CppInteropData * interopData;
  Il2CppClass * klass;
  FieldInfo * fields;
  const EventInfo * events;
  const PropertyInfo * properties;
  const MethodInfo ** methods;
  Il2CppClass ** nestedTypes;
  Il2CppClass ** implementedInterfaces;
} Il2CppClass_0;

struct Il2CppClass_1
{
  void * image;
  void * gc_desc;
  const char * name;
  const char * namespaze;
  Il2CppType byval_arg;
  Il2CppType this_arg;
  Il2CppClass * element_class;
  Il2CppClass * castClass;
  Il2CppClass * declaringType;
  Il2CppClass * parent;
  void * generic_class;
  void * typeDefinition;
  void * interopData;
  Il2CppClass * klass;
  void * fields;
  void * events;
  void * properties;
  void * methods;
  Il2CppClass ** nestedTypes;
  Il2CppClass ** implementedInterfaces;
  Il2CppRuntimeInterfaceOffsetPair * interfaceOffsets;
};

struct Il2CppClass_2
{
  Il2CppClass ** typeHierarchy;
  uint32_t initializationExceptionGCHandle;
  uint32_t cctor_started;
  uint32_t cctor_finished;
  uint64_t cctor_thread;
  int32_t genericContainerIndex;
  uint32_t instance_size;
  uint32_t actualSize;
  uint32_t element_size;
  int32_t native_size;
  uint32_t static_fields_size;
  uint32_t thread_static_fields_size;
  int32_t thread_static_fields_offset;
  uint32_t flags;
  uint32_t token;
  uint16_t method_count;
  uint16_t property_count;
  uint16_t field_count;
  uint16_t event_count;
  uint16_t nested_type_count;
  uint16_t vtable_count;
  uint16_t interfaces_count;
  uint16_t interface_offsets_count;
  uint8_t typeHierarchyDepth;
  uint8_t genericRecursionDepth;
  uint8_t rank;
  uint8_t minimumAlignment;
  uint8_t naturalAligment;
  uint8_t packingSize;
  uint8_t bitflags1;
  uint8_t bitflags2;
};

struct Il2CppClass
{
  Il2CppClass_1 _1;
  void * static_fields;
  Il2CppRGCTXData * rgctx_data;
  Il2CppClass_2 _2;
  VirtualInvokeData vtable[255];
};

struct Il2CppArrayBounds
{
  il2cpp_array_size_t length;
  il2cpp_array_lower_bound_t lower_bound;
};

struct MethodInfo
{
  Il2CppMethodPointer methodPointer;
  void * invoker_method;
  const char * name;
  Il2CppClass * klass;
  const Il2CppType * return_type;
  const void * parameters;
  union
  {
    const Il2CppRGCTXData * rgctx_data;
    const void * methodDefinition;
  };
  union
  {
    const void * genericMethod;
    const void * genericContainer;
  };
  uint32_t token;
  uint16_t flags;
  uint16_t iflags;
  uint16_t slot;
  uint8_t parameters_count;
  uint8_t bitflags;
};

struct __declspec( align( 4 ) ) System_String_Fields
{
  int32_t m_stringLength;
  uint16_t m_firstChar;
};
struct System_String_o
{
  int32_t m_stringLength;
  uint16_t m_firstChar;
};

struct System_DateTime_o
{
  uint64_t dateData;
};

struct System_Guid_o
{
  int32_t _a;
  int16_t _b;
  int16_t _c;
  uint8_t _d;
  uint8_t _e;
  uint8_t _f;
  uint8_t _g;
  uint8_t _h;
  uint8_t _i;
  uint8_t _j;
  uint8_t _k;
};

struct System_TimeSpan_o
{
  int64_t _ticks;
};

struct UnityEngine_Vector2_o
{
  float x;
  float y;
};

struct __declspec( align( 4 ) ) UnityEngine_Object_Fields
{
  intptr_t m_CachedPtr;
};

struct UnityEngine_Component_Fields : UnityEngine_Object_Fields
{
};

struct UnityEngine_Behaviour_Fields : UnityEngine_Component_Fields
{
};

struct UnityEngine_MonoBehaviour_Fields : UnityEngine_Behaviour_Fields
{
};

struct PlayerHandler_Fields : UnityEngine_MonoBehaviour_Fields
{
  struct UIRoot_o * _UIRoot;
  struct UnityEngine_Transform_o * HUDPokemon;
  struct PanelSorter_o * _PanelSorter;
  struct UnityEngine_Transform_o * PokeCardParent;
  struct ScriptHandler_o * _ScriptHandler;
  struct FollowPokemon_o * _FollowPokemon;
  struct UnityEngine_GameObject_o * ReconnectionPanel;
  struct InputHandler_o * inputHandler;
  struct System_String_o * Username;
  bool LoggedIn;
  struct UISprite_o * BatterySprite;
  struct UnityEngine_Color_array * BatteryColours;
  struct UnityEngine_GameObject_o * PleaseWait;
  int32_t WildCounter;
  uint32_t CurrentSteps;
  struct PSXAPI_Response_Level_o * Level;
  struct PSXAPI_Response_Equip_o * CurrentEquip;
  int32_t StaffRank;
  int32_t Season;
  float LastMovedDirection;
  struct CharacterHandler_o * Character;
  struct System_String_array * DiscoveredAreas;
  struct GUICharacter_o * GUIChar;
  struct UILabel_o * lblLevel;
  struct UILabel_o * lblUsername;
  struct ChatBubble_o * _ChatBubble;
  struct EmoteBubble_o * _EmoteBubble;
  struct UnityEngine_GameObject_array * ContextMenuPrefab;
  struct UnityEngine_GameObject_o * RightClickParent;
  struct PSXAPI_Response_Path_o * Path;
  struct UnityEngine_Vector2_o lastClick;
  int32_t lastRunCount;
  bool gotoPath;
  float rndfloat;
  float rndfloat2;
  float PosX;
  float PosY;
  struct UnityEngine_Coroutine_o * cancelRoutine;
  struct TweenWidth_o * tw;
  uint32_t totalExp;
  int32_t newtotalExp;
  struct UISprite_o * SpritePlayerEXP;
  struct UISprite_o * SpritePlayerEXPDark;
  struct UILabel_o * trainerExpLabel;
  float lastTimeLabelUpdate;
  struct UILabel_o * lblGameTime;
  struct System_DateTime_o LastTimeUpdate;
  struct System_TimeSpan_o gametime;
  double timeFactor;
  int32_t lastHour;
  struct PSXAPI_Response_Time_o * time;
  float GameTimeCheck;
  struct UIPanel_o * Blackout;
  bool KeyMapChange;
  struct System_Guid_o SyncID;
  bool WaitforSync;
  bool SyncOnLoad;
  struct System_String_o * mapChatChannel;
  struct UnityEngine_Vector2_o MovementDelta;
  float ZoomDelta;
  int32_t CurrentDirection;
  float MountTime;
  int32_t pathIndex;
  struct UnityEngine_GameObject_array * ArcadeMachines;
  float stutterFix;
  float holdTime;
  struct System_Collections_Generic_List_float__o * timestamps;
  float WildWait;
  float lastBumpPlayed;
  struct UnityEngine_GameObject_o * MessageBoxPrefab;
  struct UnityEngine_GameObject_o * GUIRoot;
  struct UnityEngine_GameObject_o * SplashPrefab;
  struct UnityEngine_GameObject_o * SplashParent;
  bool LOSing;
  bool WaitForScripts;
  bool DontRunScript;
  struct PSXAPI_Response_Battle_o * loginBattle;
  struct System_Collections_Generic_List_PokemonCard__o * PokeCards;
  struct CharacterName_o * PlayerName;
};

struct PlayerHandler_StaticFields
{
  struct String * UsernameLower;
  struct PlayerHandler * Instance;
  struct Vector2 InputMovement;
  bool InputSelected;
};

struct PlayerHandler_VTable
{
  VirtualInvokeData Equals;
  VirtualInvokeData Finalize;
  VirtualInvokeData GetHashCode;
  VirtualInvokeData ToString;
};

struct PlayerHandler_Class
{
  Il2CppClass_0 _0;
  Il2CppRuntimeInterfaceOffsetPair * interfaceOffsets;
  struct PlayerHandler_StaticFields * static_fields;
  const Il2CppRGCTXData * rgctx_data;
  Il2CppClass_1 _1;
  struct PlayerHandler_VTable vtable;
};

struct PlayerHandler
{
  struct PlayerHandler_Class * klass;
  MonitorData * monitor;
  struct PlayerHandler_Fields fields;
};

struct __declspec( align( 4 ) ) PSXUtilities_Move_Fields
{
  struct System_String_o * _move_k__BackingField;
  struct System_String_o * _id_k__BackingField;
  int32_t _pp_k__BackingField;
  int32_t _maxpp_k__BackingField;
  struct System_String_o * _target_k__BackingField;
  bool _disabled_k__BackingField;
};
struct PSXUtilities_Move_o
{
  PSXUtilities_Move_Fields fields;
};

struct PSXUtilities_Move_array
{
  Il2CppArrayBounds * bounds;
  il2cpp_array_size_t max_length;
  PSXUtilities_Move_o * m_Items[65535];
};

struct __declspec( align( 4 ) ) PSXUtilities_PokemonInfo_Fields
{
  int32_t ID;
  int32_t UID;
  int32_t MaxHealth;
  int32_t Health;
  bool Mega;
  int32_t Level;
  bool Shiny;
  int32_t BattlePosition;
  struct System_String_o * Gender;
  struct System_String_o * Status;
  struct PSXUtilities_Move_array * Moves;
  struct PSXUtilities_Move_array * ZMoves;
  bool isActive;
  bool forceSwitch;
  bool sendPass;
  bool forced;
  struct System_String_o * Trainer;
  int32_t Personality;
  bool Trapped;
  bool MaybeTrapped;
  struct System_String_o * Ability;
  struct System_String_o * Forme;
  bool Caught;
  bool NormalSwitch;
};

struct __declspec( align( 4 ) ) BattlePokeHandler_BattleInfos_Fields
{
  struct System_String_o * Level;
  struct System_String_o * Gender;
  struct System_String_o * Status;
  int32_t Personality;
};

struct __declspec( align( 4 ) ) PSXUtilities_PokedexInfo_Fields
{
  int32_t ID;
  struct System_String_o * BattleID;
  struct System_String_o * Form;
  struct System_String_o * Name;
  struct System_String_o * Description;
  struct System_String_o * Type;
  struct System_String_o * Type2;
  int32_t HP;
  int32_t ATK;
  int32_t DEF;
  int32_t SPATK;
  int32_t SPDEF;
  int32_t SPD;
  struct System_String_o * Species;
  struct System_String_o * Height;
  struct System_String_o * Weight;
  double RatioM;
  struct System_String_o * Ability1;
  struct System_String_o * Ability2;
  struct System_String_o * Ability3;
  int32_t EVATK;
  int32_t EVDEF;
  int32_t EVSPD;
  int32_t EVSPDEF;
  int32_t EVSPATK;
  int32_t EVHP;
  int32_t EggCycles;
  int32_t CaptureRate;
  int32_t BaseHappiness;
  struct System_String_o * ExpRate;
  int32_t BaseExp;
};

struct PSXUtilities_PokedexInfo_o
{
  PSXUtilities_PokedexInfo_Fields fields;
};

struct HealthBar_Fields
{
  int32_t CurrentHP;
  int32_t MaxHP;
  struct PSXUtilities_PokedexInfo_o * PokemonInfo;
};
