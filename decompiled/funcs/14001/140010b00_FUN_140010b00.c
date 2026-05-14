// Address: 0x140010b00
// Ghidra name: FUN_140010b00
// ============ 0x140010b00 FUN_140010b00 (size=227) ============


void FUN_140010b00(longlong *param_1,longlong param_2)



{

  ulonglong uVar1;

  

  (**(code **)(*param_1 + 0x28))(param_1,0);

  switch((int)param_1[1]) {

  case 1:

  case 7:

    uVar1 = (ulonglong)DAT_1403ffa60;

    break;

  case 2:

    uVar1 = (ulonglong)DAT_1403ffa80;

    break;

  case 3:

  case 9:

    uVar1 = (ulonglong)DAT_1403ffa30;

    break;

  case 4:

    uVar1 = (ulonglong)DAT_1403ffa38;

    break;

  case 5:

  case 10:

    uVar1 = (ulonglong)DAT_1403ffa28;

    break;

  case 6:

    uVar1 = (ulonglong)DAT_1403ffa90;

    break;

  case 8:

    uVar1 = (ulonglong)DAT_1403ffa40;

    break;

  default:

    FID_conflict__assert(L"false",L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\Joints\\b2Joint.cpp",0xa6);

    return;

  }

  if (0xd < (uint)uVar1) {

    FID_conflict__assert

              (L"0 <= index && index < b2_blockSizes",

               L"C:\\dev\\Box2d2\\Box2D\\Common\\b2BlockAllocator.cpp",0xad);

  }

  *param_1 = *(longlong *)(param_2 + 0x10 + uVar1 * 8);

  *(longlong **)(param_2 + uVar1 * 8 + 0x10) = param_1;

  return;

}




