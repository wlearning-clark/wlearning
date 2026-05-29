#!/usr/bin/env lua

-- 1. data type
a = type(1) -- number
print(a)
a = type(0) -- number
print(a)
a = type("str") -- string
print(a)
a = type('c') -- string
print(a)
a = type('sq') -- string
print(a)
a = type(3.14e21) -- number
print(a)
a = type(nil)  -- nil
print(a)
a = type(1 and 2) -- number
print(a)
a = type(true) -- boolean
print(a)
a = type((nil and 3)) -- nil
print(a)
a = math.type(3) -- integer
print(a)
a = math.type(3.0) -- float
print(a)
a = print
print(a) -- function
a = {}
print(a) -- table


-- 2. numerical

print(4)
print(4.3)
print(1.3e10)
print(2.8e-3)
print(-2.6e3)
print(-7.6e-2)

print(1 == 1.000) --true
print(-1 == -1.000) -- true
print(-1.0e3 == -1000) -- true
print(-1.0e3) -- -1000.0
print(-1000) -- -1000

print(0x00)
print(0x01)
print(0x03)
print(0x07)
print(0x0f)
print(0x1f)
print(0x3f)
print(0x7f) -- 127
print(0xff) -- 255
print(0x1ff) -- 511
print(0x3ff) -- 1023
print(0x7ff) -- 2047
print(0xfff) -- 4095
print(0x1fff) -- 8191
print(0x3fff) -- 16383
print(0x7fff) -- 32767
print(0xffff) -- 65535
print(0x1ffff) -- 131071
print(0x3ffff)
print(0x7ffff)
print(0x1fffff)
print(0x3fffff)
print(0x7fffff)
print(0xffffff)

-- For Addressing Bus. it unit as bit
-- For Memory, it unit as byte that is 1 byte = 8 bit
--
-- For 8 bit
-- 0000 0000
-- Maximum addressing:
-- 1111 1111
-- Represent as hex: 
-- 0xFF
-- Write in decimal:
-- 255 
-- Actual Addressable Memory Size:
-- 0 to 255 byte => 256 byte(B)
--
-- For 16 bit
-- 0000 0000 0000 0000
-- Maximum addressing
-- 1111 1111 1111 1111
-- Represent as hex:
-- 0xFFFF
-- Write in decimal:
-- 65535
-- Actual Addressable Memory Size:
--                             KB
-- 0 to 65535 byte => 65536 / 1024  = 64 kilobyte(KB)
--
-- 32 bit
-- 0000 0000 0000 0000 0000 0000 0000 0000
-- Maximum addressing
-- 1111 1111 1111 1111 1111 1111 1111 1111
-- Represent as hex:
-- 0xFFFFFFFF
-- Write in decimal:
-- 4294967295
-- Actual Addressable Memory Size:
--                                       KB     MB     GB
-- 0 to 4294967295 byte => 4294967296 / 1024 / 1024 / 1024 = 4 gigabyte(GB)
-- 
-- 64 bit
-- 0000 0000 0000 0000 0000 0000 0000 0000
-- 0000 0000 0000 0000 0000 0000 0000 0000
-- Maximum addressing
-- 1111 1111 1111 1111 1111 1111 1111 1111
-- 1111 1111 1111 1111 1111 1111 1111 1111
-- Represent as hex:
-- 0xFFFFFFFF_FFFFFFFF
-- Write in decimal:
-- 1.844674407×10¹⁹
-- Actual Addressable Memory Size:
--                                                    KB     MB     GB     TB     PB     EB
-- 0 to 1.844674407×10¹⁹ => (1.844674407×10¹⁹ + 1) / 1024 / 1024 / 1024 / 1024 / 1024 / 1024 = 16 exabyte(EB)

