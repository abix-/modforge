// Address: 0x140012800
// Ghidra name: FUN_140012800
// ============ 0x140012800 FUN_140012800 (size=170) ============


void FUN_140012800(longlong param_1,undefined8 *param_2,int param_3)



{

  byte bVar1;

  

  if (param_3 != 0) {

    if (param_3 < 1) {

      FID_conflict__assert(L"0 < size",L"C:\\dev\\Box2d2\\Box2D\\Common\\b2BlockAllocator.cpp",0xa4)

      ;

    }

    else if (0x280 < param_3) {

      thunk_FUN_1402e9a80(param_2);

      return;

    }

    bVar1 = (&DAT_1403ff940)[param_3];

    if (0xd < bVar1) {

      FID_conflict__assert

                (L"0 <= index && index < b2_blockSizes",

                 L"C:\\dev\\Box2d2\\Box2D\\Common\\b2BlockAllocator.cpp",0xad);

    }

    *param_2 = *(undefined8 *)(param_1 + 0x10 + (ulonglong)bVar1 * 8);

    *(undefined8 **)(param_1 + (ulonglong)bVar1 * 8 + 0x10) = param_2;

  }

  return;

}




