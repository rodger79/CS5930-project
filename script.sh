email:

grep -E "\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,6}\b"  user-ct-test-collection-10.txt >> ~/school/CS5930/project/source/email.txt
rodger@rodger-K55A:~/school/CS5930/project/AOL_search_data_leak_2006/AOL-user-ct-collection$ 

SSN:
dashes or no dashes:
grep '[0-9]\{3\}-\{0,1\}[0-9]\{2\}-\{0,1\}[0-9]\{4\}' user-ct-test-collection-05.txt >> ~/school/CS5930/project/source/ssn.txt
dashes 
grep '[0-9]\{3\}-[0-9]\{2\}-[0-9]\{4\}' user-ct-test-collection-10.txt >> ~/school/CS5930/project/source/ssn.txt

Userid:
grep 'ID' user-ct-test-collection-10.txt >> ~/school/CS5930/project/source/userID.txt

Credit card numbers
grep "^(?:4[0-9]{12}(?:[0-9]{3})?|5[1-5][0-9]{14}|3[47][0-9]{13})$" user-ct-test-collection-01.txt >> ~/school/CS5930/project/source/CC.txt

Birthday
grep 'birthday' user-ct-test-collection-01.txt >> ~/school/CS5930/project/source/birthday.txt

Macabre
grep 'hide body' user-ct-test-collection-01.txt >> ~/school/CS5930/project/source/macabre.txt
