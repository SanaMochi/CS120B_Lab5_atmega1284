# Test file for "Lab5_atmega1284chip"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
#test "PINA: 0x00, PINB: 0x00 => PORTC: 0"
# Set inputs
#setPINA 0x00
#setPINB 0x00
# Continue for several ticks
#continue 2
# Set expect values
#expectPORTC 0
# Check pass/fail
#checkResult

# Add tests below

#Test 1 empty
test "PINA: 0x00 => PORTC: 0x40"
setPINA 0x00
continue 5
expectPORTC 0x40
checkresult

#Range 2
test "PINA: 0x31 => PORTC: 0x60"
setPINA 0x31
continue 5
expectPORTC 0x60
checkresult

#Range 3
test "PINA: 0x34 => PORTC: 0x70"
setPINA 0x34
continue 5
expectPORTC 0x70
checkresult

#Range 4
test "PINA: 0x25 => PORTC: 0x38"
setPINA 0x25
continue 5
expectPORTC 0x38
checkresult

#Range 5
test "PINA: 0x48 => PORTC: 0x3C"
setPINA 0x48
continue 5
expectPORTC 0x3C
checkresult

#Range 6
test "PINA: 0x5A => PORTC: 0x3E"
setPINA 0x5A
continue 5
expectPORTC 0x3E
checkresult

#Range 7 (max)
test "PINA: 0x7F => PORTC: 0x3F"
setPINA 0x7F
continue 5
expectPORTC 0x3F
checkresult


# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
