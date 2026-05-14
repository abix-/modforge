// Address: 0x1402084f0
// Ghidra name: FUN_1402084f0
// ============ 0x1402084f0 FUN_1402084f0 (size=90) ============


void FUN_1402084f0(longlong param_1,short *param_2)



{

  undefined8 uVar1;

  int iVar2;

  longlong lVar3;

  

  if (((param_2 != (short *)0x0) && (*param_2 != 0)) &&

     ((lVar3 = *(longlong *)(param_1 + 0x28), lVar3 == 0 ||

      (iVar2 = FUN_140208de0(param_2,lVar3), iVar2 != 0)))) {

    FUN_1401841e0(lVar3);

    uVar1 = FUN_1402073f0(param_2);

    *(undefined8 *)(param_1 + 0x28) = uVar1;

    FUN_140208b70(param_1);

  }

  return;

}




