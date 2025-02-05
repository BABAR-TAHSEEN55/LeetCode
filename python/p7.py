# # s1 = input("Enter your name\n")  
# # s2 = input("Enter your Fullname\n")  
# #
# # length = 0
# # for i in s1:
# #     length += 1
# # print(length)
# #
# # if (len(s1) == len(s2)):  
# #     for i in range(len(s1)):  
# #         if s1[i] != s2[i]:
# #             print("It is not Equal")
# #             break
# #     else:  # This else runs only if the loop completes without break
# #         print("It is Equal")
# # else:
# #     print("It is not equal")
# #
# #
# # if s1.find('e')!=-1:
# #     print("Element Found ")
# # else :
# #     print('element not found')
# #
# #
# # count = 0;
# # c = input("Enter the elemtn to be searched")
# # for i in range(len(s1)):
# #     if(s1[i]==c):
# #         count+=1
# # print("It is foudn " ,count)
# #
# #
# def Count_words(file_path):
#     try:
#         with open(file_path , "r") as file:
#             text = file.read()
#             words = text.split()
#             return len(words)
#     except:
#         return "File Not Found"
# check = Count_words("../C/mergeSort.c")
# print(check)
