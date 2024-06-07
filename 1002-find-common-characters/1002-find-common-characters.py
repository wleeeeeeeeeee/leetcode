class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        
        def letter_counter(word:str):
            common_char = dict()
            for each_char in word:
                if each_char not in common_char:
                    common_char[each_char] = 1
                else:
                    common_char[each_char] += 1
            return common_char
        
        
        common_counter = letter_counter(words[0])
        
        for current_word in words :
            current_counter = letter_counter(current_word)
            new_common_counter = dict()
            for each_char in current_counter.keys():
                if each_char in common_counter.keys():
                    new_common_counter[each_char] = min(current_counter[each_char], common_counter[each_char])
            
            common_counter = new_common_counter
        
        sorted_counter = sorted(common_counter)
        answer = []
        for com_char in sorted_counter:
            answer.extend([com_char] * common_counter[com_char])
        return answer
                