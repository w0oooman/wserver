

-- 调试打印函数,itype=nil 且 _LUA_DEBUG=true 输出,itype 为真时全输出,由全局 _DEBUG 控制
function look(Obj,itype)
	if not _LUA_DEBUG and not itype then return end
	if type(Obj) ~= "table" then
		Log(tostring(Obj))
		return
	end

	local function Save(Obj, Level)
		local Blank = ""

		for i = 1, Level do
			Blank = Blank .. "   "
		end

		for k,v in pairs(Obj) do
			if tostring(k) ~= "" and v ~= Obj then
				if type(v) ~= "table" then
					Log(Blank.. " [".. tostring(k).. "] = "..tostring(v))
				else
					Log(Blank.. " [".. tostring(k).. "] = {")	
					Save(v, Level + 2)
					Log(Blank.."     },")	
				end
			end
		end
	end
	
	Log("   {")
	Save(Obj, 1)
	Log("   }")
end
