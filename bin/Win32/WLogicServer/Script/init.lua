
--全局debug控制
_LUA_DEBUG=true
--_LUA_DEBUG=false

--------------------------------------------------------------------------
--其实lua内部已经封装了一个dofile(luaB_dofile)函数
--------------------------------------------------------------------------
function dofile(filename)
	local newstring = filename;
	--Log("lua dofile("..newstring..")");

	local ret,errstring = Dofile(newstring)
	if (ret == nil) then
		--print("error in _old_dofile()!");
		return
	end

	-- if(ret == 0) then
	-- 		--rfalse("load "..newstring.." OK!")
	-- elseif(ret == 1) then
	-- 		rfalse("load "..newstring..", Error run!")
	-- elseif(ret == 2) then
	-- 		rfalse("load "..newstring..", Error lua file!")
	-- elseif(ret == 3) then
	-- 		rfalse( "load "..newstring..", Error syntax!" )
	-- elseif(ret == 4) then
	-- 		rfalse("load "..newstring..", Error lua memory!")
	-- elseif(ret == 5) then
	-- 		rfalse("load "..newstring..", Error user error error!")
	-- else
	-- 		rfalse("load "..newstring.." don't known!!")
	-- end
end

-----------------------------------------------------------------------




-------------------------------------------------------------------------

----------------------加载所有文件---------------------------------------
dofile("Script/config/init.lua")
dofile("Script/tools/init.lua")
dofile("Script/server/init.lua")
dofile("Script/player/init.lua")



