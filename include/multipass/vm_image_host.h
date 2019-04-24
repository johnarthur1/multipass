/*
 * Copyright (C) 2017-2019 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MULTIPASS_VM_IMAGE_HOST_H
#define MULTIPASS_VM_IMAGE_HOST_H

#include <multipass/optional.h>
#include <multipass/vm_image_info.h>

#include <functional>
#include <string>
#include <vector>

namespace multipass
{
class Query;
class VMImage;
class VMImageHost
{
public:
    using Action = std::function<void(const std::string&, const VMImageInfo&)>;

    virtual ~VMImageHost() = default;
    virtual optional<VMImageInfo> info_for(const Query& query) = 0;
    virtual std::vector<VMImageInfo> all_info_for(const Query& query) = 0;
    virtual VMImageInfo info_for_full_hash(const std::string& full_hash) = 0;
    virtual std::vector<VMImageInfo> all_images_for(const std::string& remote_name, const bool allow_unsupported) = 0;
    virtual void for_each_entry_do(const Action& action) = 0;
    virtual std::vector<std::string> supported_remotes() = 0;

protected:
    VMImageHost() = default;
    VMImageHost(const VMImageHost&) = delete;
    VMImageHost& operator=(const VMImageHost&) = delete;
};
}
#endif // MULTIPASS_VM_IMAGE_HOST_H
