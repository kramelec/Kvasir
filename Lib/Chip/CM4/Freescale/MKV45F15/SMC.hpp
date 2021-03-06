#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//System Mode Controller
    namespace SmcPmprot{    ///<Power Mode Protection register
        using Addr = Register::Address<0x4007e000,0xffffff5d,0x00000000,unsigned char>;
        ///Allow Very-Low-Leakage Stop Mode
        enum class AvllsVal {
            v0=0x00000000,     ///<Any VLLSx mode is not allowed
            v1=0x00000001,     ///<Any VLLSx mode is allowed
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,AvllsVal> avlls{}; 
        namespace AvllsValC{
            constexpr Register::FieldValue<decltype(avlls)::Type,AvllsVal::v0> v0{};
            constexpr Register::FieldValue<decltype(avlls)::Type,AvllsVal::v1> v1{};
        }
        ///Allow Very-Low-Power Modes
        enum class AvlpVal {
            v0=0x00000000,     ///<VLPR, VLPW, and VLPS are not allowed.
            v1=0x00000001,     ///<VLPR, VLPW, and VLPS are allowed.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,AvlpVal> avlp{}; 
        namespace AvlpValC{
            constexpr Register::FieldValue<decltype(avlp)::Type,AvlpVal::v0> v0{};
            constexpr Register::FieldValue<decltype(avlp)::Type,AvlpVal::v1> v1{};
        }
        ///Allow High Speed Run mode
        enum class AhsrunVal {
            v0=0x00000000,     ///<HSRUN is not allowed
            v1=0x00000001,     ///<HSRUN is allowed
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,AhsrunVal> ahsrun{}; 
        namespace AhsrunValC{
            constexpr Register::FieldValue<decltype(ahsrun)::Type,AhsrunVal::v0> v0{};
            constexpr Register::FieldValue<decltype(ahsrun)::Type,AhsrunVal::v1> v1{};
        }
    }
    namespace SmcPmctrl{    ///<Power Mode Control register
        using Addr = Register::Address<0x4007e001,0xffffff90,0x00000000,unsigned char>;
        ///Stop Mode Control
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,0),Register::ReadWriteAccess,unsigned> stopm{}; 
        ///Stop Aborted
        enum class StopaVal {
            v0=0x00000000,     ///<The previous stop mode entry was successsful.
            v1=0x00000001,     ///<The previous stop mode entry was aborted.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,StopaVal> stopa{}; 
        namespace StopaValC{
            constexpr Register::FieldValue<decltype(stopa)::Type,StopaVal::v0> v0{};
            constexpr Register::FieldValue<decltype(stopa)::Type,StopaVal::v1> v1{};
        }
        ///Run Mode Control
        enum class RunmVal {
            v00=0x00000000,     ///<Normal Run mode (RUN)
            v10=0x00000002,     ///<Very-Low-Power Run mode (VLPR)
            v11=0x00000003,     ///<High Speed Run mode (HSRUN)
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,5),Register::ReadWriteAccess,RunmVal> runm{}; 
        namespace RunmValC{
            constexpr Register::FieldValue<decltype(runm)::Type,RunmVal::v00> v00{};
            constexpr Register::FieldValue<decltype(runm)::Type,RunmVal::v10> v10{};
            constexpr Register::FieldValue<decltype(runm)::Type,RunmVal::v11> v11{};
        }
    }
    namespace SmcStopctrl{    ///<Stop Control Register
        using Addr = Register::Address<0x4007e002,0xffffff00,0x00000000,unsigned char>;
        ///VLLS Mode Control
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,0),Register::ReadWriteAccess,unsigned> vllsm{}; 
        ///LPO Power Option
        enum class LpopoVal {
            v0=0x00000000,     ///<LPO clock is enabled in LLS/VLLSx
            v1=0x00000001,     ///<LPO clock is disabled in LLS/VLLSx
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,LpopoVal> lpopo{}; 
        namespace LpopoValC{
            constexpr Register::FieldValue<decltype(lpopo)::Type,LpopoVal::v0> v0{};
            constexpr Register::FieldValue<decltype(lpopo)::Type,LpopoVal::v1> v1{};
        }
        ///RAM2 Power Option
        enum class Ram2poVal {
            v0=0x00000000,     ///<RAM2 not powered in VLLS2
            v1=0x00000001,     ///<RAM2 powered in VLLS2
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,Ram2poVal> ram2po{}; 
        namespace Ram2poValC{
            constexpr Register::FieldValue<decltype(ram2po)::Type,Ram2poVal::v0> v0{};
            constexpr Register::FieldValue<decltype(ram2po)::Type,Ram2poVal::v1> v1{};
        }
        ///POR Power Option
        enum class PorpoVal {
            v0=0x00000000,     ///<POR detect circuit is enabled in VLLS0
            v1=0x00000001,     ///<POR detect circuit is disabled in VLLS0
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,PorpoVal> porpo{}; 
        namespace PorpoValC{
            constexpr Register::FieldValue<decltype(porpo)::Type,PorpoVal::v0> v0{};
            constexpr Register::FieldValue<decltype(porpo)::Type,PorpoVal::v1> v1{};
        }
        ///Partial Stop Option
        enum class PstopoVal {
            v00=0x00000000,     ///<STOP - Normal Stop mode
            v01=0x00000001,     ///<PSTOP1 - Partial Stop with both system and bus clocks disabled
            v10=0x00000002,     ///<PSTOP2 - Partial Stop with system clock disabled and bus clock enabled
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,6),Register::ReadWriteAccess,PstopoVal> pstopo{}; 
        namespace PstopoValC{
            constexpr Register::FieldValue<decltype(pstopo)::Type,PstopoVal::v00> v00{};
            constexpr Register::FieldValue<decltype(pstopo)::Type,PstopoVal::v01> v01{};
            constexpr Register::FieldValue<decltype(pstopo)::Type,PstopoVal::v10> v10{};
        }
    }
    namespace SmcPmstat{    ///<Power Mode Status register
        using Addr = Register::Address<0x4007e003,0xffffff00,0x00000000,unsigned char>;
        ///Power Mode Status
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> pmstat{}; 
    }
}
