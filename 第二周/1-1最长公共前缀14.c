/*最长公共前缀14
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。*/
char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize==0)
    {
         return (char*)calloc(1, sizeof(char)); // 分配一个空字符串
    }
     int i = 0;
    while (1) {//以第一个字符串为基准，逐个字符比较
        char current_char = strs[0][i];// 取出当前基准字符（第0个字符串的第i位）
        // 遍历所有字符串，检查第i位是否一致
        for (int j = 0; j < strsSize; j++) {
            // 终止条件：
            // ① 当前字符串已经结束（长度不够）
            // ② 字符和基准不一致
            if (strs[j][i] == '\0' || strs[j][i] != current_char) {
                // 分配空间存储结果（前i个字符 + 结束符）
                char* result = (char*)malloc((i + 1) * sizeof(char));
                strncpy(result, strs[0], i); // 复制前i个字符
                result[i] = '\0';            // 手动添加结束符
                return result;
            }
        }
        i++; // 所有字符串的第i位都一致，继续下一位
    }
}//自写
char* longestCommonPrefix(char** strs, int strsSize) {

    if (strsSize == 0)
        return "";

    for (int i = 0; strs[0][i] != '\0'; i++) {
        char c = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] == '\0' || strs[j][i] != c) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0];
}//最小内存