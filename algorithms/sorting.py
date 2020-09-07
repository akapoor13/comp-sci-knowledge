class Array:
    def __init__(self):
        self.data = [None]
        self.items = 0
        self.size = 1

    def print_data(self):
        for i in self.data:
            print(i)

        print(self.items)
        print(self.size)

    def insert(self, value, pos=None):
        if (pos == None):
            pos = self.size-1

        newSize = self.size
        if (pos >= newSize):
            while(pos >= newSize):
                newSize *= 2

            temp = [None] * newSize
            for i in range(self.size-1):
                temp[i] = self.data[i]

            self.data = temp

        self.data[pos] = value
        self.size = newSize
        self.items += 1


item = Array()
item.insert(1)
item.insert(2)
item.insert(3)
item.print_data()
