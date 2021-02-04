def split(array, left, right):
    pivot = array[left]
    while left < right:
        while left < right and array[right] >= pivot:
            right -= 1
        array[left] = array[right]
        while left < right and array[left] <= pivot:
            left += 1
        array[right] = array[left]
    array[left] = pivot;
    return left
def quickSort(array, left, right):
    if left <= right:
        pos = split(array, left, right)
        quickSort(array, left, pos - 1)
        quickSort(array, pos + 1, right)

if __name__ == "__main__":
    num = int(input().strip())
    array = list(map(int, input().split()))
    quickSort(array, 0, num - 1)
    for i in range(num):
        print(array[i], end=' ')