## 1. Definition
RAII is a C++ programming idiom where resource management (memory, files, locks, etc.) is tied to the lifetime of an object.  
- Resource is acquired in the constructor.  
- Resource is released in the destructor.  

---

## 2. Core Idea
- When an object goes **out of scope**, its destructor is automatically called.  
- This guarantees proper cleanup, even if exceptions are thrown.  

---

## 3. Examples
- **Memory:** `std::unique_ptr` automatically frees memory.  
- **File handling:** `std::ifstream` closes the file in its destructor.  
- **Synchronization:** `std::lock_guard` unlocks a mutex when destroyed.  

---

## 4. Benefits
- No manual `delete` or `close` → fewer leaks and errors.  
- Exception safety: cleanup always happens.  
- Clear ownership: resource tied to object’s scope.  

---

## 5. Key Takeaways
- RAII = scope-based resource management.  
- Always prefer RAII wrappers (`unique_ptr`, `shared_ptr`, `lock_guard`, etc.).  
- Enables safe, exception-resilient C++ code.
