typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Definition of the hash set data structure
typedef struct {
    Node** table;
    int size;
} HashSet;

HashSet* createHashSet(int size) {
    HashSet* hashSet = (HashSet*)malloc(sizeof(HashSet));
    hashSet->table = (Node**)malloc(size * sizeof(Node*));
    hashSet->size = size;
    for (int i = 0; i < size; i++) {
        hashSet->table[i] = NULL;
    }
    return hashSet;
}

void insert(HashSet* hashSet, int key) {
    int index = abs(key) % hashSet->size;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = key;
    newNode->next = NULL;

    Node* head = hashSet->table[index];
    if (head == NULL) {
        hashSet->table[index] = newNode;
    } else {
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = newNode;
    }
}

bool contains(HashSet* hashSet, int key) {
    int index = abs(key) % hashSet->size;
    Node* head = hashSet->table[index];
    while (head != NULL) {
        if (head->value == key) {
            return true;  // Duplicate found
        }
        head = head->next;
    }
    return false;  // No duplicates found
}

void freeHashSet(HashSet* hashSet) {
    for (int i = 0; i < hashSet->size; i++) {
        Node* head = hashSet->table[i];
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            free(temp);
        }
    }
    free(hashSet->table);
    free(hashSet);
}

bool containsDuplicate(int* nums, int numsSize) {
    HashSet* hashSet = createHashSet(numsSize);

    for (int i = 0; i < numsSize; i++) {
        if (contains(hashSet, nums[i])) {
            freeHashSet(hashSet);
            return true;  // Duplicate found
        }
        insert(hashSet, nums[i]);
    }

    freeHashSet(hashSet);
    return false;  // No duplicates found
}