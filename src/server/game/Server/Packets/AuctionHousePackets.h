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

#ifndef AuctionHousePackets_h__
#define AuctionHousePackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "ItemPacketsCommon.h"

namespace WorldPackets
{
    namespace AuctionHouse
    {
        struct AuctionItem
        {
            struct AuctionItemEnchant
            {
                AuctionItemEnchant(int32 id, uint32 expiration, int32 charges, uint8 slot) : ID(id), Expiration(expiration), Charges(charges), Slot(slot) { }
                int32 ID = 0;
                uint32 Expiration = 0;
                int32 Charges = 0;
                uint8 Slot = 0;
            };

            Item::ItemInstance Item;
            int32 Count = 0;
            int32 Charges = 0;
            std::vector<AuctionItemEnchant> Enchantments;
            int32 Flags = 0;
            int32 AuctionItemID = 0;
            ObjectGuid Owner;
            uint64 MinBid = 0;
            uint64 MinIncrement = 0;
            uint64 BuyoutPrice = 0;
            int32 DurationLeft = 0;
            uint8 DeleteReason = 0;
            bool CensorServerSideInfo = false;
            bool CensorBidInfo = false;
            ObjectGuid ItemGuid;
            ObjectGuid OwnerAccountID;
            uint32 EndTime = 0;
            ObjectGuid Bidder;
            uint64 BidAmount = 0;
        };

        class AuctionReplicateItems final : public ClientPacket
        {
        public:
            AuctionReplicateItems(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_REPLICATE_ITEMS, std::move(packet)) { }

            void Read() override;

            ObjectGuid Auctioneer;
            uint32 ChangeNumberGlobal = 0;
            uint32 ChangeNumberCursor = 0;
            uint32 ChangeNumberTombstone = 0;
            uint32 Count = 0;
        };

        class AuctionReplicateResponse final : public ServerPacket
        {
        public:
            AuctionReplicateResponse() : ServerPacket(SMSG_AUCTION_REPLICATE_RESPONSE, 165) { }

            WorldPacket const* Write() override;

            uint32 ChangeNumberCursor = 0;
            uint32 ChangeNumberGlobal = 0;
            uint32 DesiredDelay = 0;
            uint32 ChangeNumberTombstone = 0;
            uint32 Result = 0;
            std::vector<AuctionItem> Items;
        };
    }
}

#endif