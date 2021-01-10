def solution(phone_book):
    answer = True
    phone_book.sort();
    for cmp in range(0, len(phone_book)):
        for tmp in range(cmp+1, len(phone_book)):
            if phone_book[tmp].find(phone_book[cmp]) !=-1:
                return False;
    return answer
