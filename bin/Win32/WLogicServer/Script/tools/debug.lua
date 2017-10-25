
-- -- 调试打印函数,itype=nil 且 _LUA_DEBUG=true 输出,itype 为真时全输出,由全局 _DEBUG 控制
-- function look(Obj,itype)
-- 	if not _LUA_DEBUG and not itype then return end
-- 	if type(Obj) ~= "table" then
-- 		Log(tostring(Obj))
-- 		return
-- 	end

-- 	local function Save(Obj, Level)
-- 		local Blank = ""

-- 		for i = 1, Level do
-- 			Blank = Blank .. "   "
-- 		end

-- 		for k,v in pairs(Obj) do
-- 			if tostring(k) ~= "" and v ~= Obj then
-- 				if type(v) ~= "table" then
-- 					Log(Blank.. " [".. tostring(k).. "] = "..tostring(v))
-- 				else
-- 					Log(Blank.. " [".. tostring(k).. "] = {")	
-- 					Save(v, Level + 2)
-- 					Log(Blank.."     },")	
-- 				end
-- 			end
-- 		end
-- 	end
	
-- 	Log("   {")
-- 	Save(Obj, 1)
-- 	Log("   }")
-- end

-- 调试打印函数,itype=nil 且 _LUA_DEBUG=true 输出,itype 为真时全输出,由全局 _DEBUG 控制
function look(t, itype)
	if not _LUA_DEBUG and not itype then return end
	local function _print(t,stimes)
		stimes = stimes or 0
	
		local space = ""
		for i=1,stimes do
			space = space.."    "
		end
			
		if type(t) == "table" then
			Log(space.."{")
			for k,v in pairs(t)do
				local key
				if type(k) == "string" then
					key = k
				else
					key = "["..tostring(k).."]"
				end
					
				if type(v) ~= "table" then
					if type(v) == "string" then
						Log(space.."    "..key.."=".."\""..v.."\""..",")
					else
						Log(space.."    "..key.."="..tostring(v)..",")
					end
				else
					Log(space.."    "..key.."=")
					_print(v, stimes+1)
				end
			end
			Log(space.."},")
		else
			Log(tostring(t))
		end	
	end
	_print(t)
end