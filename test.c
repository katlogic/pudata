#include <lua.h>
#include <lauxlib.h>
#include <assert.h>

#include "pudata.h"

int main()
{
  lua_State *L = luaL_newstate();
  int top = lua_gettop(L);
  void *p = lua_newuserdata(L, 1);
  assert(top == lua_gettop(L)-1);
  lua_pushuserdata(L, p);
  assert(top == lua_gettop(L)-2);
  assert(lua_rawequal(L, -1, -2));
  lua_pop(L, 2);
  lua_gc(L, LUA_GCCOLLECT, 0);
  lua_pushuserdata(L, p);
  assert(lua_isnil(L, -1));
}