//
//  SGPath.h
//
//  Copyright 2014 ON Semiconductor.
//  All rights reserved. This software and/or documentation is licensed by ON Semiconductor under
//  limited terms and conditions. The terms and conditions pertaining to the software and/or documentation are available at
//  http://www.onsemi.com/site/pdf/ONSEMI_T&C.pdf (“ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software”).
//  Do not use this software and/or documentation unless you have carefully read and you agree to the limited terms and conditions.
//  By using this software and/or documentation, you agree to the limited terms and conditions.
//
//  Copyright 2019 ON Semiconductor
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#ifndef SGPATH_H
#define SGPATH_H

#include <string>

namespace Strata {

    class SGPath {
    public:
        SGPath(){};
        SGPath(const std::string& path);
        virtual ~SGPath(){};
        void constructPath(const std::string& p);
        bool isValidDir();
        bool mkdir();
        void addChildDir(const std::string& dirname);
        const std::string &getPath() const;
    private:
        std::string path_;

#ifdef _WIN32
        static constexpr const char kSGSeparatorChar_ = '\\';
        static constexpr const char *kSGCurrentDir = ".\\";
#else
        static constexpr const char kSGSeparatorChar_ = '/';
        static constexpr const char *kSGCurrentDir = "./";
#endif
    };
}



#endif //SGPATH_H
