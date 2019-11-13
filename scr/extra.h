#ifndef _EXTRA_H_
#define _EXTRA_H_

#ifndef FALLOUT_VERSION
#define FALLOUT_VERSION 2
#endif

#include "parse.h"
#include "parselib.h"

//
// Parse library functions.  Given the procedure list and
// what token was just parsed.  Parse everything up to but
// not including the ending ; for this statement.
void parseExtraStatement(Procedure *, NodeList*, int);
void parseExtraExpression(Procedure *p, NodeList*, int i);

//
// code generation function for extra opcodes.
// receives the parsed list of things, the position in that
// list, and the stream to write to.  Generate code, and return
// the position in the last immediately *after* the the statement
// written.
int writeExtraStatement(NodeList *n, int i, FILE *);

// write out an expression (library functions that return values)
// These are kind of annoying, since the statement versions have
// to realize they are in a statement instead of in an expression.
// For the statement version, you have to generate the call to the
// interpreter function, and follow it with a pop_stack opcode.
// This means that you have to have code generators in both the
// extra statement and extra expression functions (or, if you're
// clever, you can recursively call writeStatement from
// writeExtraExpression, and let writeExtraExpression conditionally
// write out the pop if it can figure out it's in a statement).
int writeExtraExpression(NodeList *n, int i, FILE *f);


// all extra tokens and their meanings
void initLexExtras(void);

#include "opextra.h"

enum {
	C_END_CONSTANT = C_END_LIB,
};

enum {
	// define any user-specific tokens here, starting with T_END_LIB,
	// ending with T_END_TOKEN
	T_GIVE_EXP_POINTS = T_END_LIB,
	T_SCR_RETURN,
	T_PLAY_SFX,
	T_OBJ_NAME,
	T_SFX_BUILD_OPEN_NAME,
	T_GET_PC_STAT,
	T_TILE_CONTAINS_PID_OBJ,
	T_SET_MAP_START,
	T_OVERRIDE_MAP_START,
	T_HAS_SKILL,
	T_USING_SKILL,
	T_ROLL_VS_SKILL,
	T_SKILL_CONTEST,
	T_DO_CHECK,
	T_IS_SUCCESS,
	T_IS_CRITICAL,
	T_HOW_MUCH,

#if (FALLOUT_VERSION == 2)
	T_MARK_AREA_KNOWN,
#else
	T_REACTION,
#endif

	T_REACTION_INFLUENCE,
	T_RANDOM,
	T_ROLL_DICE,
	T_MOVE_TO,
	T_CREATE_OBJECT_SID,
	T_DISPLAY_MSG,
	T_SCRIPT_OVERRIDES,
	T_OBJ_IS_CARRYING_OBJ_PID,
	T_TILE_CONTAINS_OBJ_PID,
	T_SELF_OBJ,
	T_SOURCE_OBJ,
	T_TARGET_OBJ,
	T_DUDE_OBJ,
	T_OBJ_BEING_USED_WITH,
	T_LOCAL_VAR,
	T_SET_LOCAL_VAR,
	T_MAP_VAR,
	T_SET_MAP_VAR,
	T_GLOBAL_VAR,
	T_SET_GLOBAL_VAR,
	T_SCRIPT_ACTION,
	T_OBJ_TYPE,
	T_OBJ_ITEM_SUBTYPE,
	T_GET_CRITTER_STAT,
	T_SET_CRITTER_STAT,
	T_ANIMATE_STAND_OBJ,
	T_ANIMATE_STAND_REVERSE_OBJ,
	T_ANIMATE_MOVE_OBJ_TO_TILE,

#if (FALLOUT_VERSION == 2)
	T_TILE_IN_TILE_RECT,
#else
	T_ANIMATE_JUMP,
#endif

	T_ATTACK_COMPLEX,
	T_MAKE_DAYTIME,
	T_TILE_DISTANCE,
	T_TILE_DISTANCE_OBJS,
	T_TILE_NUM,
	T_TILE_NUM_IN_DIRECTION,
	T_PICKUP_OBJ,
	T_DROP_OBJ,
	T_ADD_OBJ_TO_INVEN,
	T_RM_OBJ_FROM_INVEN,
	T_WIELD_OBJ_CRITTER,
	T_USE_OBJ,
	T_OBJ_CAN_SEE_OBJ,
	T_ATTACK,
	T_START_GDIALOG,
	T_END_DIALOGUE,
	T_DIALOGUE_REACTION,

#if (FALLOUT_VERSION == 2)
	T_METARULE3,
	T_SET_MAP_MUSIC,
#else
	T_TURN_OFF_OBJS_IN_AREA,
	T_TURN_ON_OBJS_IN_AREA,
#endif

	T_SET_OBJ_VISIBILITY,
	T_LOAD_MAP,

#if (FALLOUT_VERSION == 2)
	T_WM_AREA_SET_POS,
	T_SET_EXIT_GRIDS,
#else
	T_BARTER_OFFER,
	T_BARTER_ASKING,
#endif

	T_ANIM_BUSY,
	T_CRITTER_HEAL,
	T_SET_LIGHT_LEVEL,
	T_GAME_TIME,
	T_GAME_TIME_IN_SECONDS,
	T_ELEVATION,
	T_KILL_CRITTER,
	T_KILL_CRITTER_TYPE,
	T_CRITTER_DMG,
	T_ADD_TIMER_EVENT,
	T_RM_TIMER_EVENT,
	T_GAME_TICKS,
	T_HAS_TRAIT,
	T_DESTROY_OBJECT,
	T_OBJ_CAN_HEAR_OBJ,
	T_GAME_TIME_HOUR,
	T_FIXED_PARAM,
	T_TILE_IS_VISIBLE,
	T_DIALOGUE_SYSTEM_ENTER,
	T_ACTION_BEING_USED,
	T_CRITTER_STATE,
	T_GAME_TIME_ADVANCE,
	T_RADIATION_INC,
	T_RADIATION_DEC,
	T_CRITTER_ATTEMPT_PLACEMENT,
	T_OBJ_PID,
	T_CUR_MAP_INDEX,
	T_CRITTER_ADD_TRAIT,
	T_CRITTER_RM_TRAIT,
	T_PROTO_DATA,
	T_MESSAGE_STR,
	T_CRITTER_INVEN_OBJ,
	T_OBJ_SET_LIGHT_LEVEL,
	T_WORLD_MAP,

#if (FALLOUT_VERSION == 2)
	T_INVEN_CMDS,
#else
	T_TOWN_MAP,
#endif

	T_FLOAT_MSG,
	T_METARULE,
	T_ANIM,
	T_OBJ_CARRYING_PID_OBJ,
	T_REG_ANIM_FUNC,
	T_REG_ANIM_ANIMATE,
	T_REG_ANIM_ANIMATE_REVERSE,
	T_REG_ANIM_OBJ_MOVE_TO_OBJ,
	T_REG_ANIM_OBJ_RUN_TO_OBJ,
	T_REG_ANIM_OBJ_MOVE_TO_TILE,
	T_REG_ANIM_OBJ_RUN_TO_TILE,
	T_PLAY_GMOVIE,
	T_ADD_MULT_OBJS_TO_INVEN,
	T_RM_MULT_OBJS_FROM_INVEN,
	T_GET_MONTH,
	T_GET_DAY,
	T_EXPLOSION,
	T_DAYS_SINCE_VISITED,
	T_GSAY_START,
	T_GSAY_END,
	T_GSAY_REPLY,
	T_GSAY_OPTION,
	T_GSAY_MESSAGE,
	T_GIQ_OPTION,
	T_POISON,
	T_GET_POISON,
	T_PARTY_ADD,
	T_PARTY_REMOVE,
	T_REG_ANIM_ANIMATE_FOREVER,
	T_CRITTER_INJURE,
	T_COMBAT_IS_INITIALIZED,
	T_GDIALOG_MOD_BARTER,
	T_DIFFICULTY_LEVEL,
	T_RUNNING_BURNING_GUY,
	T_INVEN_UNWIELD,
	T_OBJ_IS_LOCKED,
	T_OBJ_LOCK,
	T_OBJ_UNLOCK,
	T_OBJ_IS_OPEN,
	T_OBJ_OPEN,
	T_OBJ_CLOSE,
	T_GAME_UI_DISABLE,
	T_GAME_UI_ENABLE,
	T_GAME_UI_IS_DISABLED,
	T_GFADE_OUT,
	T_GFADE_IN,
	T_ITEM_CAPS_TOTAL,
	T_ITEM_CAPS_ADJUST,
	T_ANIM_ACTION_FRAME,
	T_REG_ANIM_PLAY_SFX,
	T_CRITTER_MOD_SKILL,
	T_SFX_BUILD_CHAR_NAME,
	T_SFX_BUILD_AMBIENT_NAME,
	T_SFX_BUILD_INTERFACE_NAME,
	T_SFX_BUILD_ITEM_NAME,
	T_SFX_BUILD_WEAPON_NAME,
	T_SFX_BUILD_SCENERY_NAME,
	T_ATTACK_SETUP,
	T_DESTROY_MULT_OBJS,
	T_USE_OBJ_ON_OBJ,
	T_ENDGAME_SLIDESHOW,
	T_MOVE_OBJ_INVEN_TO_OBJ,
	T_ENDGAME_MOVIE,
	T_OBJ_ART_FID,
	T_ART_ANIM,
	T_PARTY_MEMBER_OBJ,
	T_ROTATION_TO_TILE,
	T_JAM_LOCK,
	T_GDIALOG_SET_BARTER_MOD,
	T_COMBAT_DIFFICULTY,
	T_OBJ_ON_SCREEN,
	T_CRITTER_IS_FLEEING,
	T_CRITTER_SET_FLEE_STATE,
	T_TERMINATE_COMBAT,
	T_DEBUG_MSG,
	T_CRITTER_STOP_ATTACKING,

	T_TS_READ_BYTE,
	T_TS_READ_SHORT,
	T_TS_READ_INT,
	T_TS_READ_STRING,
	T_TS_SET_PC_BASE_STAT,
	T_TS_SET_PC_EXTRA_STAT,
	T_TS_GET_PC_BASE_STAT,
	T_TS_GET_PC_EXTRA_STAT,
	T_TS_SET_CRITTER_BASE_STAT,
	T_TS_SET_CRITTER_EXTRA_STAT,
	T_TS_GET_CRITTER_BASE_STAT,
	T_TS_GET_CRITTER_EXTRA_STAT,
	T_TS_TAP_KEY,
	T_TS_GET_YEAR,
	T_TS_GAME_LOADED,
	T_TS_GRAPHICS_FUNCS_AVAILABLE,
	T_TS_LOAD_SHADER,
	T_TS_FREE_SHADER,
	T_TS_ACTIVATE_SHADER,
	T_TS_DEACTIVATE_SHADER,
	T_TS_SET_GLOBAL_SCRIPT_REPEAT,
	T_TS_INPUT_FUNCS_AVAILABLE,
	T_TS_KEY_PRESSED,

	T_TS_SET_SHADER_INT,
	T_TS_SET_SHADER_FLOAT,
	T_TS_SET_SHADER_VECTOR,
	T_TS_IN_WORLD_MAP,
	T_TS_FORCE_ENCOUNTER,
	T_TS_SET_WORLD_MAP_POS,
	T_TS_GET_WORLD_MAP_X_POS,
	T_TS_GET_WORLD_MAP_Y_POS,

	T_TS_SET_DM_MODEL,
	T_TS_SET_DF_MODEL,
	T_TS_SET_MOVIE_PATH,

	T_TS_SET_PERK_IMAGE,
	T_TS_SET_PERK_RANKS,
	T_TS_SET_PERK_LEVEL,
	T_TS_SET_PERK_STAT,
	T_TS_SET_PERK_STAT_MAG,
	T_TS_SET_PERK_SKILL1,
	T_TS_SET_PERK_SKILl1_MAG,
	T_TS_SET_PERK_TYPE,
	T_TS_SET_PERK_SKILL2,
	T_TS_SET_PERK_SKILL2_MAG,
	T_TS_SET_PERK_STR,
	T_TS_SET_PERK_PER,
	T_TS_SET_PERK_END,
	T_TS_SET_PERK_CHR,
	T_TS_SET_PERK_INT,
	T_TS_SET_PERK_AGL,
	T_TS_SET_PERK_LCK,
	T_TS_SET_PERK_NAME,
	T_TS_SET_PERK_DESC,

	T_TS_SET_PIPBOY_AVAILABLE,

	T_TS_GET_KILL_COUNTER,
	T_TS_MOD_KILL_COUNTER,

	T_TS_GET_PERK_OWED,
	T_TS_SET_PERK_OWED,
	T_TS_GET_PERK_AVAILABLE,

	T_TS_GET_CRITTER_AP,
	T_TS_SET_CRITTER_AP,

	T_TS_GET_ACTIVE_HAND,
	T_TS_TOGGLE_ACTIVE_HAND,

	T_TS_SET_WEAPON_KNOCKBACK,
	T_TS_SET_TARGET_KNOCKBACK,
	T_TS_SET_ATTACKER_KNOCKBACK,
	T_TS_REMOVE_WEAPON_KNOCKBACK,
	T_TS_REMOVE_TARGET_KNOCKBACK,
	T_TS_REMOVE_ATTACKER_KNOCKBACK,

	T_TS_SET_GLOBAL_SCRIPT_TYPE,
	T_TS_AVAILABLE_GLOBAL_SCRIPT_TYPES,

	T_TS_SET_SFALL_GLOBAL,
	T_TS_GET_SFALL_GLOBAL_INT,
	T_TS_GET_SFALL_GLOBAL_FLOAT,

	T_TS_SET_PICKPOCKET_MAX,
	T_TS_SET_HIT_CHANCE_MAX,
	T_TS_SET_SKILL_MAX,

	T_TS_EAX_AVAILABLE,
	T_TS_SET_EAX_ENVIRONMENT,

	T_TS_INC_NPC_LEVEL,

	T_TS_GET_VIEWPORT_X,
	T_TS_GET_VIEWPORT_Y,
	T_TS_SET_VIEWPORT_X,
	T_TS_SET_VIEWPORT_Y,

	T_TS_SET_XP_MOD,
	T_TS_SET_PERK_LEVEL_MOD,

	T_TS_GET_INI_SETTING,

	T_TS_GET_SHADER_VERSION,
	T_TS_SET_SHADER_MODE,

	T_TS_GET_GAME_MODE,

	T_TS_FORCE_GRAPHICS_REFRESH,
	T_TS_GET_SHADER_TEXTURE,
	T_TS_SET_SHADER_TEXTURE,

	T_TS_GET_UPTIME,

	T_TS_SET_STAT_MAX,
	T_TS_SET_STAT_MIN,

	T_TS_SET_CAR_CURRENT_TOWN,

	T_TS_SET_PC_STAT_MAX,
	T_TS_SET_PC_STAT_MIN,
	T_TS_SET_NPC_STAT_MAX,
	T_TS_SET_NPC_STAT_MIN,

	T_TS_SET_FAKE_PERK,
	T_TS_SET_FAKE_TRAIT,
	T_TS_SET_SELECTABLE_PERK,
	T_TS_SET_PERKBOX_TITLE,
	T_TS_HIDE_REAL_PERKS,
	T_TS_SHOW_REAL_PERKS,
	T_TS_HAS_FAKE_PERK,
	T_TS_HAS_FAKE_TRAIT,
	T_TS_PERK_ADD_MODE,
	T_TS_CLEAR_SELECTABLE_PERKS,

	T_TS_SET_CRITTER_HIT_CHANCE_MOD,
	T_TS_SET_BASE_HIT_CHANCE_MOD,
	T_TS_SET_CRITTER_SKILL_MOD,
	T_TS_SET_BASE_SKILL_MOD,
	T_TS_SET_CRITTER_PICKPOCKET_MOD,
	T_TS_SET_BASE_PICKPOCKET_MOD,

	T_TS_SET_PYROMANIAC_MOD,
	T_TS_APPLY_HEAVEHO_FIX,
	T_TS_SET_SWIFTLEARNER_MOD,
	T_TS_SET_HP_LEVEL_MOD,

	T_TS_WRITE_BYTE,
	T_TS_WRITE_SHORT,
	T_TS_WRITE_INT,

	T_TS_CALL_OFFSET_V0,
	T_TS_CALL_OFFSET_V1,
	T_TS_CALL_OFFSET_V2,
	T_TS_CALL_OFFSET_V3,
	T_TS_CALL_OFFSET_V4,
	T_TS_CALL_OFFSET_R0,
	T_TS_CALL_OFFSET_R1,
	T_TS_CALL_OFFSET_R2,
	T_TS_CALL_OFFSET_R3,
	T_TS_CALL_OFFSET_R4,

	T_TS_SHOW_IFACE_TAG,
	T_TS_HIDE_IFACE_TAG,
	T_TS_IS_IFACE_TAG_ACTIVE,

	T_TS_GET_BODYPART_HIT_MODIFIER,
	T_TS_SET_BODYPART_HIT_MODIFIER,

	T_TS_SET_CRITICAL_TABLE,
	T_TS_GET_CRITICAL_TABLE,
	T_TS_RESET_CRITICAL_TABLE,

	T_TS_GET_SFALL_ARG,
	T_TS_SET_SFALL_RETURN,

	T_TS_SET_UNSPENT_AP_BONUS,
	T_TS_GET_UNSPENT_AP_BONUS,
	T_TS_SET_UNSPENT_AP_EBONUS,
	T_TS_GET_UNSPENT_AP_EBONUS,

	T_TS_INIT_HOOK,

	T_TS_GET_INI_STRING,

	T_TS_SQRT,
	T_TS_ABS,
	T_TS_SIN,
	T_TS_COS,
	T_TS_TAN,
	T_TS_ATAN,

	//T_TS_CREATE_BUTTON,
	T_TS_SET_PALETTE,
	//T_TS_BUTTON_PRESSED,

	T_TS_REMOVE_SCRIPT,
	T_TS_SET_SCRIPT,
	T_TS_GET_SCRIPT,

	T_TS_NB_CREATE_CHAR,

	T_TS_FS_CREATE,
	T_TS_FS_COPY,
	T_TS_FS_FIND,
	T_TS_FS_WRITE_BYTE,
	T_TS_FS_WRITE_SHORT,
	T_TS_FS_WRITE_INT,
	T_TS_FS_WRITE_FLOAT,
	T_TS_FS_WRITE_STRING,
	T_TS_FS_DELETE,
	T_TS_FS_SIZE,
	T_TS_FS_POS,
	T_TS_FS_SEEK,
	T_TS_FS_RESIZE,

	T_TS_GET_PROTO_DATA,
	T_TS_SET_PROTO_DATA,

	T_TS_SET_SELF,
	T_TS_REGISTER_HOOK,

	T_TS_FS_WRITE_BSTRING,
	T_TS_FS_READ_BYTE,
	T_TS_FS_READ_SHORT,
	T_TS_FS_READ_INT,
	T_TS_FS_READ_FLOAT,

	T_TS_LIST_BEGIN,
	T_TS_LIST_NEXT,
	T_TS_LIST_END,

	T_TS_SFALL_VER_MAJOR,
	T_TS_SFALL_VER_MINOR,
	T_TS_SFALL_VER_BUILD,

	T_TS_HERO_SELECT_WIN,
	T_TS_SET_HERO_RACE,
	T_TS_SET_HERO_STYLE,

	T_TS_SET_CRITTER_BURST_DISABLE,

	T_TS_GET_WEAPON_AMMO_PID,
	T_TS_SET_WEAPON_AMMO_PID,
	T_TS_GET_WEAPON_AMMO_COUNT,
	T_TS_SET_WEAPON_AMMO_COUNT,

	T_TS_WRITE_STRING,

	T_TS_GET_MOUSE_X,
	T_TS_GET_MOUSE_Y,
	T_TS_GET_MOUSE_BUTTONS,
	T_TS_GET_WINDOW_UNDER_MOUSE,
	T_TS_GET_SCREEN_WIDTH,
	T_TS_GET_SCREEN_HEIGHT,
	T_TS_STOP_GAME,
	T_TS_RESUME_GAME,
	T_TS_CREATE_MESSAGE_WINDOW,
	T_TS_REMOVE_TRAIT,
	T_TS_GET_LIGHT_LEVEL,

	T_TS_REFRESH_PC_ART,
	T_TS_GET_ATTACK_TYPE,

	T_TS_FORCE_ENCOUNTER_WITH_FLAGS,

	T_TS_SET_MAP_TIME_MULTI,

	T_TS_PLAY_SFALL_SOUND,
	T_TS_STOP_SFALL_SOUND,

	T_TS_CREATE_ARRAY,
	T_TS_SET_ARRAY,
	T_TS_GET_ARRAY,
	T_TS_FREE_ARRAY,
	T_TS_LEN_ARRAY,
	T_TS_RESIZE_ARRAY,
	T_TS_TEMP_ARRAY,
	T_TS_FIX_ARRAY,
	T_TS_SCAN_ARRAY,

	T_TS_STRING_SPLIT,

	T_TS_LIST_AS_ARRAY,

	T_TS_ATOI,
	T_TS_ATOF,

	T_TS_TILE_PID,

	T_TS_MODIFIED_INI,

	T_TS_GET_SFALL_ARGS,
	T_TS_SET_SFALL_ARG,

	T_TS_FORCE_AIMED_SHOTS,
	T_TS_DISABLE_AIMED_SHOTS,

	T_TS_MARK_MOVIE_PLAYED,

	T_TS_GET_NPC_LEVEL,

	T_TS_SET_CRITTER_SKILL_POINTS,
	T_TS_GET_CRITTER_SKILL_POINTS,
	T_TS_SET_AVAILABLE_SKILL_POINTS,
	T_TS_GET_AVAILABLE_SKILL_POINTS,
	T_TS_MOD_SKILL_POINTS_PER_LEVEL,
	T_TS_SET_PERK_FREQ,

	T_TS_GET_LAST_ATTACKER,
	T_TS_GET_LAST_TARGET,
	T_TS_BLOCK_COMBAT,

	T_TS_TILE_UNDER_CURSOR,
	T_TS_GET_BARTER_MOD,
	T_TS_SET_INVEN_AP_COST,

	T_TS_SUBSTR,
	T_TS_STRLEN,
	T_TS_SPRINTF,
	T_TS_ORD,
	T_TS_RESERVD2,
	T_TS_TYPEOF,

	T_TS_SAVE_ARRAY,
	T_TS_LOAD_ARRAY,
	T_TS_GET_ARRAY_KEY,
	T_TS_STACK_ARRAY,
	T_TS_RESERVD3,
	T_TS_RESERVD4,

	T_TS_REG_ANIM_DESTROY,
	T_TS_REG_ANIM_ANIMATE_AND_HIDE,
	T_TS_REG_ANIM_COMBAT_CHECK,
	T_TS_REG_ANIM_LIGHT,
	T_TS_REG_ANIM_CHANGE_FID,
	T_TS_REG_ANIM_TAKE_OUT,
	T_TS_REG_ANIM_TURN_TOWARDS,

	T_TS_EXPLOSIONS_METARULE,

	T_TS_REGISTER_HOOK_PROC,

	T_TS_LOG,
	T_TS_EXP,
	T_TS_CEIL,
	T_TS_ROUND,

	T_TS_MESSAGE_STR_GAME,
	T_TS_SNEAK_SUCCESS,
	T_TS_TILE_LIGHT,
	T_TS_MAKE_STRAIGHT_PATH,
	T_TS_OBJ_BLOCKING_AT,
	T_TS_TILE_GET_OBJECTS,
	T_TS_GET_PARTY_MEMBERS,
	T_TS_PATH_FIND,
	T_TS_CREATE_SPATIAL,
	T_TS_ART_EXISTS,
	T_TS_OBJ_IS_CARRYING_OBJ,

	T_TS_SFALL_METARULE0,
	T_TS_SFALL_METARULE1,
	T_TS_SFALL_METARULE2,
	T_TS_SFALL_METARULE3,
	T_TS_SFALL_METARULE4,
	T_TS_SFALL_METARULE5,
	T_TS_SFALL_METARULE6,
	
	T_TS_REGISTER_HOOK_PROC2,
	T_TS_REG_ANIM_CALLBACK,

	T_END_TOKEN
};

#endif
