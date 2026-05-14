// Address: 0x1402181b0
// Ghidra name: FUN_1402181b0
// ============ 0x1402181b0 FUN_1402181b0 (size=152) ============


undefined4 FUN_1402181b0(undefined8 *param_1,int param_2)



{

  uint *puVar1;

  undefined8 uVar2;

  undefined4 uVar3;

  longlong lVar4;

  ulonglong uVar5;

  

  puVar1 = (uint *)*param_1;

  if (puVar1 == (uint *)0x0) {

LAB_140218230:

    uVar3 = 0;

  }

  else {

    lVar4 = param_1[2];

    uVar5 = (ulonglong)((*puVar1 >> 3 & 0x1f) * puVar1[1] * param_2);

    if ((ulonglong)param_1[4] < uVar5) {

      uVar2 = FUN_14017fc90();

      lVar4 = FUN_140190080(uVar2,uVar5);

      if (lVar4 == 0) goto LAB_140218230;

      FUN_140190140(param_1[2]);

      param_1[2] = lVar4;

      param_1[4] = uVar5;

    }

    param_1[3] = uVar5;

    uVar3 = FUN_14015e760(*puVar1);

    FUN_1402f94c0(lVar4,uVar3,uVar5);

    uVar3 = 1;

  }

  return uVar3;

}




