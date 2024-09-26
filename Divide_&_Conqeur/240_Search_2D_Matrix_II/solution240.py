class Solution:
    def divide_and_conquer(self, mat, min_i, min_j, max_i, max_j, tar):
        if min_i > max_i or min_j > max_j:
            return False

        med_i = (min_i + max_i) // 2
        med_j = (min_j + max_j) // 2
        if mat[med_i][med_j] == tar:
            return True
        if mat[med_i][med_j] > tar:
            if self.divide_and_conquer(mat, min_i, min_j, max_i, med_j - 1, tar):
                return True
            if self.divide_and_conquer(mat, min_i, med_j, med_i - 1, max_j, tar):
                return True
        else:
            if self.divide_and_conquer(mat, med_i + 1, min_j, max_i, max_j, tar): 
                return True
            if self.divide_and_conquer(mat, min_i, med_j + 1, med_i, max_j, tar): 
                return True

        return False
        
    def searchMatrix(self, mat: List[List[int]], tar: int) -> bool:
        return self.divide_and_conquer(mat, 0, 0, len(mat)-1, len(mat[0])-1, tar)