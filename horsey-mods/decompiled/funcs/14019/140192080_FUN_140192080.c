// Address: 0x140192080
// Ghidra name: FUN_140192080
// ============ 0x140192080 FUN_140192080 (size=99) ============


void FUN_140192080(undefined8 param_1,undefined8 param_2,longlong *param_3,longlong *param_4)



{

  longlong lVar1;

  

  lVar1 = FUN_1401841f0(0x50);

  if (lVar1 != 0) {

    FUN_140192130(param_2,lVar1);

    if (*param_4 == 0) {

      *param_3 = lVar1;

    }

    else {

      *(longlong *)(*param_4 + 0x48) = lVar1;

    }

    *param_4 = lVar1;

  }

  return;

}




