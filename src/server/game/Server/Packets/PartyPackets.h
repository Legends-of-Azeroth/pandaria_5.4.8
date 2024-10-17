/*
 * This file is part of the Legends of Azeroth Pandaria Project. See THANKS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PartyPackets_h__
#define PartyPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Group.h"

namespace WorldPackets
{
    namespace Party
    {
        class SendRaidTargetUpdateAll final : public ServerPacket
        {
        public:
            SendRaidTargetUpdateAll() : ServerPacket(SMSG_RAID_TARGET_UPDATE_ALL, 1 + TARGETICONCOUNT * 9) { }

            WorldPacket const* Write() override;

            int8 PartyIndex = 0;
            std::map<uint8, ObjectGuid> TargetIcons;
        };
    }
}

#endif // PartyPackets_h__
