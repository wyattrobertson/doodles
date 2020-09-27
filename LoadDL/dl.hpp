
#ifndef LOADDL_DL_HPP
#define LOADDL_DL_HPP

#include <string>
#include <dlfcn.h>
#include <stdexcept>
#include <functional>
#include <iostream>


class DynamicLibraryParser
{
    public:
    
        DynamicLibraryParser(const std::string& dynamic_library_path)
        {
            void* dynamic_library_handle = dlopen(dynamic_library_path.c_str(), RTLD_LAZY);
            if (!dynamic_library_handle)
            {
                throw std::runtime_error("Could not load dynamic library");
            }
            m_handle = dynamic_library_handle;
        }

        ~DynamicLibraryParser()
        {
            if (m_handle)
            {
                int ret = dlclose(m_handle);
                if (ret != 0)
                {
                    printf("Dynamic library was not unloaded properly\n");
                }
            }
        }

        template<typename F>
        std::function<F> getFunction(const std::string& function_name)
        {
            if (m_handle)
            {
                void* initializer = dlsym(m_handle, function_name.c_str());
                if (!initializer)
                {
                    throw std::runtime_error("Could not fetch function from dynamic library");
                }
                return reinterpret_cast<F*>(initializer);
            }
            throw std::runtime_error("Dynamic library handle is not valid");
        }

    private:
        void* m_handle = nullptr;
};

#endif // LOADDL_DL_HPP