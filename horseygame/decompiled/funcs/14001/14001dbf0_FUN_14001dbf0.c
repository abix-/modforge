// Address: 0x14001dbf0
// Ghidra name: FUN_14001dbf0
// ============ 0x14001dbf0 FUN_14001dbf0 (size=98) ============


void FUN_14001dbf0(longlong *param_1,longlong param_2)



{

  uint uVar1;

  

  (**(code **)(*param_1 + 8))(param_1,0);

  uVar1 = (uint)DAT_1403ffa08;

  if (0xd < uVar1) {

    FID_conflict__assert

              (L"0 <= index && index < b2_blockSizes",

               L"C:\\dev\\Box2d2\\Box2D\\Common\\b2BlockAllocator.cpp",0xad);

  }

  *param_1 = *(longlong *)(param_2 + 0x10 + (ulonglong)uVar1 * 8);

  *(longlong **)(param_2 + (ulonglong)uVar1 * 8 + 0x10) = param_1;

  return;

}




