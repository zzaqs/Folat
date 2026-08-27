# Testing main interpreter

out AAA aaa
jwc tst 000 # exc = false, seg = "tst"
out BBB bbb # shouldn't be executed
--- tst ---
out CCC ccc
ext 000 001
# expexted: AAAaaaCCCccc