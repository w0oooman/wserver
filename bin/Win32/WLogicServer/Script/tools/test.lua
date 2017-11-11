


--------------------------------test-----------------------------------


-----------------------lua coroutine测试-------------------------------------------------
function foo(a)
    print("foo", a)
    return coroutine.yield(2 * a)
end

co = coroutine.create(function ( a, b )
    print("co-body", a, b)
    local r = foo(a + 1)
    print("co-body", r)
    local r, s = coroutine.yield(a + b, a - b)
    print("co-body", r, s)
    return b, "end"
end)

print("main", coroutine.resume(co, 1, 10))
-- print("main", coroutine.resume(co, "r"))
-- print("main", coroutine.resume(co, "x", "y"))
-- print("main", coroutine.resume(co, "x", "y"))


-----------------------lua json-- dkjson.lua 实现-------------------------------------------------
-- local test = {2,5,"hehe",}
-- local test2 = {2,5,"hehe",abc = "ttx",["1"] = 7,}

-- local seri = json.encode(test)
-- local unseri = json.decode(seri)
-- print("seri="..seri)              -- seri=[2,5,"hehe"]

-- seri = json.encode(test2)
-- unseri = json.decode(seri)
-- print("seri="..seri)              -- seri={"1":2,"2":5,"3":"hehe","abc":"ttx","1":7}
-- look(unseri)
--    {
--     [abc] = ttx
--     [1] = 7
--     [2] = 5
--     [3] = hehe
--    }
-----------------------c json-- lua-cjson-2.1.0 实现-------------------------------------------------
-- local json = require 'cjson'

-- local test = {2,5,"hehe",}
-- local test2 = {2,5,"hehe",abc = "ttx",["1"] = 7,}

-- local seri = json.encode(test)
-- local unseri = json.decode(seri)
-- print("seri="..seri)              -- seri=[2,5,"hehe"]

-- seri = json.encode(test2)         -- 序列化bug，{[1]=2,["1"]=3}类似于这种序列化不能区分开!!!
-- unseri = json.decode(seri)        
-- print("seri="..seri)              -- seri={"1":2,"2":5,"3":"hehe","1":7,"abc":"ttx"}
-- look(unseri) 
 -- {
 --  [abc] = tt
 --  [3] = hehe
 --  [2] = 5.0
 --  [1] = 7.0
 -- }


-- local tt = {1,2,"tew",["1"] = "bby"}
-- look(tt[1]) -- 1
-- look(tt["1"]) -- bby
-- look(tt)
-- for k,v in pairs(tt) do
--   print(k.."="..v)
-- end

-----------------------------string.pack----------------------------------------
-- Letter Codes
-- z : zero-terminated string 
-- p : string preceded by length byte 
-- P : string preceded by length word 
-- a : string preceded by length size_t 
-- A : string 
-- f : float 
-- d : double 
-- n : Lua number 
-- c : char 
-- b : byte (unsigned char) 
-- h : short 
-- H : unsigned short 
-- i : int 
-- I : unsigned int 
-- l : long 
-- L : unsigned long

-- < : little endian 
-- > : big endian 
-- = : native endian

-- local test = string.pack("HHI",8,2,3) -- test is binary data
-- --look(test) -- error,test is binary data

-- local val,val2,val3 = string.unpack("HHI",test,1)
-- look(val) -- 8
-- look(val2) -- 2
-- look(val3) -- 3


-----------------------------dark luaEx_serialize----------------------------------------

-- 用一个字节表示序列化信息,当key、value都是数字,用03 表示,高4位分成两部分(key和value)，0000表示key只有1个byte,0001->2,0010->3,0011->4,同理
-- 0000表示value只有1个byte,0100->2,1000->3,1100->4;把key、value合1起来，则如果一个key 3位，value 2位([65537] = 257),则序列化后为63 010001 0101

-- len = 30 whb
-- c1 01 61 41 42 43 00 81 02 61 62 63 0a 61 02 79 02 02 78 01 02 7a 03 4a 03 08 04 03 10 0a 00
-- c1    01 61 41 42 43   00 81    02 61 62 63    0a 61   02  79 02  02  78 01 02  7a 03   4a  03 08 04  03 10 0a   00
-- SaveTable(tostring("dbTables\\test.ldb"),{"aABC","abc",[8] = 4,[16] = 10, a = {x  = 1,y=2,z=3}})

-- c1    01 61 41 42 43 32  00 81   02 61 62 63   0a 61   02 79 02  02 78 01  13 fc 03 64  02 7a 03  4a 81  07 70 70 70  03 08 04  03 10 0a   00
-- SaveTable(tostring("dbTables\\test.ldb"),{"aABC2","abc",[8] = 4,[16] = 10, a = {x  = 1,y=2,z=3,[1020] = 100,} ,[7] ="ppp",})

-- [1] = "abc",       [2]="aABC2",                   a = {x  = 1,y=2,z=3,[1020] = 100,            }      [16] = 10  [7] ="ppp"        e = "ce"       d = "c"     [8] = 4   cde = "mn"
-- 81   01 61 62 63   c1  02 61 41 42 43 32 00   0a  61  02 79 02  02 78 01  13  fc 03 64  02 7a 03  4a  03 10 0a   81  07 70 70 70   40  65 63 65   00  64 63   03 08 04  60  63 64 65 6d 6e -- ?.abc?.aABC2..a.y..x..?.d.z.J...?.ppp@ece.dc...`cdem0x15BA0054  
-- SaveTable(tostring("dbTables\\test.ldb"),{"abc","aABC2",d = "c",e = "ce",ce = m,cde = "mn",[8] = 4,[16] = 10, a = {x  = 1,y=2,z=3,[1020] = 100,} ,[7] ="ppp",})

--  a = {   y=2,      x  = 1,   [1020] = 100, z=3}          [7] ="ppp"         [8] = 4    [16] = 10
 -- 0a  61  02 79 02  02 78 01  13  fc 03 64  02 7a 03  4a  81   07 70 70 70   03 08 04   03 10 0a
 -- SaveTable(tostring("dbTables\\test.ldb"),{[8] = 4,[16] = 10, a = {x  = 1,y=2,z=3,[1020] = 100,} ,[7] ="ppp",})
  
-- ["9"] = 11
 -- 02 39 0b   03 10 0a   81 07 70 70 70   03 08 04   0a  61  02 79 02  02 78 01  13  fc 03 64  02 7a 03  4a  --.9....?.ppp....a.y..x..?.d.z.J
 -- SaveTable(tostring("dbTables\\test.ldb"),{[8] = 4,[16] = 10,["9"] = 11, a = {x  = 1,y=2,z=3,[1020] = 100,} ,[7] ="ppp",})

-- ab            abc              abced                     abcdefghijkl                                   [65537] = 1        [65538] = 257         abcdefghijkl     =                          1   ace = "ABCDEFG"
-- 41 01 61 62   81 02 61 62 63   c1 03 61 62 63 64 65 00   c1 04 61 62 63 64 65 66 67 68 69 6a 6b 6c 00   23  01 00 01  01   63  02 00 01  01 01   32  61 62 63 64 65 66 67 68 69 6a 6b 6c 00 01   e0  61 63 65  41 42 43 44 45 46 47
-- SaveTable(tostring("dbTables\\test.ldb"),{[65537] = 1,[65538] = 257,"ab","abc","abcde","abcdefghijkl",abcdefghijkl = 1,ace = "ABCDEFG"})

-- [65537] = 1        [65538] = 257         [65539] = 65540
-- 23  01 00 01  01   63  02 00 01  01 01   a3  03 00 01  04 00 01
-- SaveTable(tostring("dbTables\\test.ldb"),{[65537] = 1,[65538] = 257,[65539] = 65540,})

-- [2] = 65537        [257] = 1       [258] = 65538         [1] = 258
-- 83  02  01 00 01   13  01 01  01   93  02 01  02 00 01   43  01  02 01
-- SaveTable(tostring("dbTables\\test.ldb"),{[257] = 1,[1] = 258,[2] = 65537,[258] = 65538})

--  [-65537] = 1           [-65539] = -65540              [-1] = 257
-- 33  ff ff fe ff  01     f3  fd ff fe ff  fc ff fe ff   73  ff ff ff ff  01 01
-- SaveTable(tostring("dbTables\\test.ldb"),{[-65537] = 1,[-1] = 257,[-65539] = -65540,})

-- 32 61 62 63 64 65 66 67 68 69 6a 6b 6c 61 62 63 64 65 66 67 68 69 6a 6b 6c 61 62 63 64 65 66 67 68 69 6a 6b 6c 61 62 63 64 65 66 67 68 69 6a 6b 6c 61 62 63  2abcdefghijklabcdefghijklabcdefghijklabcdefghijklabc
-- 0x15BA0054  64 65 66 67 68 69 6a 6b 6c 61 62 63 64 65 66 67 68 69 6a 6b 6c 61 62 63 64 65 66 67 68 69 6a 61 62 63 64 65 66 67 68 69 6a 6b 6c 61 62 63 64 65 66 67 68 69  defghijklabcdefghijklabcdefghijabcdefghijklabcdefghi
-- 0x15BA0088  6a 6b 6c 61 62 63 64 65 66 67 68 69 6a 6b 6c 61 62 63 64 65 66 67 68 69 6a 6b 6c 61 62 63 64 65 66 67 68 69 6a 6b 6c 61 62 63 64 65 66 67 68 69 6a 6b 6c 61  jklabcdefghijklabcdefghijklabcdefghijklabcdefghijkla
-- 0x15BA00BC  62 63 64 65 66 67 68 69 6a 69 6a 6b 6c 61 62 63 64 65 66 67 68 69 6a 6b 6c 61 62 63 64 65 66 67 68 69 6a 6b 6c 61 62 63 64 65 66 67 68 69 6a 6b 6c 61 62 63  bcdefghijijklabcdefghijklabcdefghijklabcdefghijklabc
-- 0x15BA00F0  64 65 66 67 68 69 6a 6b 6c 61 62 63 64 65 66 67 68 69 6a 00 01
-- SaveTable(tostring("dbTables\\test.ldb"),{abcdefghijklabcdefghijklabcdefghijklabcdefghijklabcdefghijklabcdefghijklabcdefghijabcdefghijklabcdefghijklabcdefghijklabcdefghijklabcdefghijklabcdefghijklabcdefghijijklabcdefghijklabcdefghijklabcdefghijklabcdefghijklabcdefghij = 1})

-- a={1}                ab = 1         cd={a=1}                  b={c,d}
-- 0a  61 03 01 01 4a   12 61 62 01    1a  63 64 02 61 01  4a    0a 62 4a
-- 0a  61 03 01 01 4a   12 61 62 01    1a  63 64 02 61 01  4a    0a 62 4a
-- SaveTable(tostring("dbTables\\test.ldb"),{ab = 1,a={1},b={c,d},cd={a=1}})

-----------------------------my luaEx_Serialize----------------------------------------
look("--------------Serialize test start.---------------")
-- -- 待测试 --{9223372036854775808}
-- --local seriTest = {2,3,89,257,65534,65539,462378,748923744,4294967296,18014398509481984,72057594037927936,4611686018427387904,9223372036854775807,[234789] = 42378,[58239] = 255,[47892308]= 257,[5423987482037] = 65538,[256] = 256,[55536]=65536,[4294967296]=4294967296} 
--local seriTest = {[256] = 256,[55536]=65536,[4294967296]=4294967296,[234789] = 42378,[58239] = 255,[47892308]= 257,[5423987482037] = 65538} 
-- local seriTest = {['test']='测试中文乱码.',[1.3] = 4,[2] = 3.141592,abced = 1.210,[true] = 1,[10] = false,[false] = true, abcde = "xyz0",abe = true,a = 1.0,[4294967296]=4294967296,[256] = 256,[55536]=65536,[7.5345345] = "akfdjk;j",[1.31231231231312321313] = 0.5345353453535345353535353535353535353535353535353}
--local seriTest = {-2,3,89,257,-65534,-65539,-462378,748923744,-4294967296,18014398509481984,-72057594037927936,4611686018427387904,-9223372036854775807,[-3]=-9,[-234789] = 42378,[-58239] = 255,[47892308]= 257,[-5423987482037] = -65538,[256] = -256,[55536]=65536,[4294967296]=-4294967296,a = 1,abcd = 2,abcde = 3,[643782] = "0fhas;jkld",fjaks = "0f0weipfk8",[256] = "0fjaskdfas;dfsadioffjieaowfasj",f;ha = "fahsiofjas;fja;kls",["f;ha"] = 2,FJASKLFJI89PJFJKSAFJSJIFJSOIJFSOAJDFSKOAAFPSADIFIOPSAJDFOIASPFOSIAPJDFSIOADFPIOAJDFPSDFfjaksfjsdjfkasjfoFJFIjfjskdf = "fjksdafjs;djfsiafj[390rj0sifs0[fasmk jfsdfisjdfiosajdf[pasf[sajdifsaoddddfj[ajf[sapo]fafjsdkalfjsdkafjksadfa[ofsadfksoadkfiajfiosajf",} 
-- --local seriTest = {a = 1,abcd = 2,abcde = 3,[643782] = "0fhas;jkld",fjaks = "0f0weipfk8",[256] = "0fjaskdfas;dfsadioffjieaowfasj",f;ha = "fahsiofjas;fja;kls",["f;ha"] = 2,FJASKLFJI89PJFJKSAFJSJIFJSOIJFSOAJDFSKOAAFPSADIFIOPSAJDFOIASPFOSIAPJDFSIOADFPIOAJDFPSDFfjaksfjsdjfkasjfoFJFIjfjskdf = "fjksdafjs;djfsiafj[390rj0sifs0[fasmk jfsdfisjdfiosajdf[pasf[sajdifsaoddddfj[ajf[sapo]fafjsdkalfjsdkafjksadfa[ofsadfksoadkfiajfiosajf",}
-- --local seriTest = {a = 1,abcd = 2,abcde = 3,[643782] = "0fhas;jkld",fjaks = "0f0weipfk8",}
local seriTest =  { a = 15*60, b = {1}}
-- -- local seriTest = {[2] = "hehe2",}
-- local seriTest = {[-5423987482037] = -65538}
-- -- seriTest[4] = "hehe4"

--local seriTest = {}
local mtable = {__index = function() error("hehe") end,}--__newindex = function() error("haha") end}
setmetatable(seriTest, mtable)
seriTest.a = "gaga"
-- --look(seriTest)

local ldbfile = "ldb/test.ldb"

local testLdb = LoadTable(ldbfile)
look("testLdb=")
lookx(testLdb)


--look(testLdb)

seriTest.bbb = seriTest
seriTest.loop1 = {l1 = "test1"}
seriTest.loop1.l2 = seriTest
seriTest.loop2 = {l3 = seriTest.loop1}
seriTest.look = look
SaveTable(ldbfile, seriTest)
look("_G.seri_lua_r=")
look(_G["seri_lua_r"])

--SaveTable(ldbfile, seriTest)

-- local test = {a = "hehe"}
-- test.b = test
-- look(test)

local x = 19  -- luaV_execute OP_LOADK
--test 测试-------------------------
if 3 > 1 then -- luaV_execute OP_LT
  --local t = x -- luaV_execute OP_MOVE
  --x = nil
    --local table = {1,2}
    --local value = 21474836--2147483648--9223372036854775808
end
--i = 4890909195324358656
--SaveTable(json.encode())

-- local value = 2147483648--9223372036854775808--2147483648
-- value = value * value
-- value = value - 1 + value
-- look("value")
-- look(value)

-- look(x)

-- local y = {data = {ids=1,t="uare"},[3] = 7,[9]=10}
-- look(y)

-- local test = {2,4}  --luaV_execute
-- local t = #test  --luaV_execute

--test = nil

--local tt = math.ceil(2.1)



------------------------------gc------------------------------------------------
--判断垃圾回收
-- print(">>>>>>>>>>>>> count ="..collectgarbage("count")) --统计 内存占用
-- collectgarbage("collect")  --释放
-- print(">>>>>>>>>>>>> count ="..collectgarbage("count")) --统计 内存占用

-- local t = {}

-- print(">>>>>>>>>>>>> count ="..collectgarbage("count")) --统计 内存占用

-- for i=1,3 do
--  local temp = {}
--  temp[i] = i*2
--  t[i] = temp[i]
-- end

-- print(">>>>>>>>>>>>> count ="..collectgarbage("count")) --统计 内存占用
-- collectgarbage("collect")  --释放
-- print(">>>>>>>>>>>>> count ="..collectgarbage("count")) --统计 内存占用

-- t = nil

-- print(">>>>>>>>>>>>> count ="..collectgarbage("count")) --统计 内存占用
-- print(">>>>>>>>>>>>> count ="..collectgarbage("count")) --统计 内存占用
-- collectgarbage("collect")  --释放
-- print(">>>>>>>>>>>>> count ="..collectgarbage("count")) --统计 内存占用

------------------------------setevent------------------------------------------------
look("LUA SetEvent")
function test_event(a,b,c,d,e)
    look("test_event")
    look(a) 
    look(b)
    look(c) -- nil
    look(d)
    look(e)
end
--g_timerID = SetEvent(nil, 1000, "test_event", nil, 22, 33.3, {1,2},"hehe", true) --暂不支持table等
g_timerID = SetEvent(nil, 1000, "test_event", 1, 22, 33.3, {1,2},"hehe", true) --暂不支持table等

function test_remove()
    look("test_remove")
    ClrEvent(g_timerID)
end
--SetEvent(nil, 12000, "test_remove")

------------------------------sort------------------------------------------------
-- local test_sort = {2,3,4,7,1}
-- --local test_sort = {1,3,4,7,2}
-- --local test_sort = {1,3,4,7,2}
-- table.sort(test_sort,
--     function (a,b)
--         return a > b
--     end
-- )
-- look("test_sort")
-- look(test_sort)