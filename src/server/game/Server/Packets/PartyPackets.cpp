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

#include "PartyPackets.h"

WorldPacket const* WorldPackets::Party::SendRaidTargetUpdateAll::Write()
{
    _worldPacket.WriteBits(TargetIcons.size(), 23);

    ByteBuffer dataBuffer;

    for (auto itr = TargetIcons.begin(); itr != TargetIcons.end(); ++itr)
    {
        ObjectGuid guid = itr->second;

        _worldPacket.WriteBit(guid[2]);
        _worldPacket.WriteBit(guid[1]);
        _worldPacket.WriteBit(guid[3]);
        _worldPacket.WriteBit(guid[7]);
        _worldPacket.WriteBit(guid[6]);
        _worldPacket.WriteBit(guid[4]);
        _worldPacket.WriteBit(guid[0]);
        _worldPacket.WriteBit(guid[5]);

        dataBuffer.WriteByteSeq(guid[4]);
        dataBuffer.WriteByteSeq(guid[7]);
        dataBuffer.WriteByteSeq(guid[1]);
        dataBuffer.WriteByteSeq(guid[0]);
        dataBuffer.WriteByteSeq(guid[6]);
        dataBuffer.WriteByteSeq(guid[5]);
        dataBuffer.WriteByteSeq(guid[3]);
        dataBuffer << (uint8)itr->first;
        dataBuffer.WriteByteSeq(guid[2]);
    }

    _worldPacket.append(dataBuffer);
    _worldPacket << (uint8)PartyIndex; // 0 = home(local) group, 1 = away(LFG etc.) group

    return &_worldPacket;
}
