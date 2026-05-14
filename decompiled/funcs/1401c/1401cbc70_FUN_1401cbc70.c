// Address: 0x1401cbc70
// Ghidra name: FUN_1401cbc70
// ============ 0x1401cbc70 FUN_1401cbc70 (size=188) ============


void FUN_1401cbc70(longlong param_1,int param_2,longlong *param_3,uint param_4,longlong *param_5)



{

  longlong lVar1;

  longlong *plVar2;

  ulonglong uVar3;

  longlong lVar4;

  ulonglong uVar5;

  

  uVar5 = (ulonglong)param_4;

  lVar1 = param_1 + (longlong)param_2 * 8;

  lVar4 = *(longlong *)(lVar1 + 0x1e0);

  if (*(uint *)(lVar4 + 0x20) <= *(uint *)(lVar4 + 0x2c)) {

    FUN_1401cb360();

  }

  lVar1 = *(longlong *)(lVar1 + 0x1e0);

  uVar3 = (ulonglong)(uint)(*(int *)(lVar1 + 0x2c) * *(int *)(lVar1 + 0x24));

  lVar4 = *(longlong *)(lVar1 + 0x10) + uVar3;

  *param_5 = uVar3 + *(longlong *)(lVar1 + 0x18);

  if (param_4 != 0) {

    do {

      if (*param_3 != 0) {

        plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x110) + 0x70);

        (**(code **)(*plVar2 + 0xc0))(plVar2,1,lVar4,*param_3,param_2);

        *(int *)(lVar1 + 0x2c) = *(int *)(lVar1 + 0x2c) + 1;

        lVar4 = lVar4 + (ulonglong)*(uint *)(lVar1 + 0x24);

      }

      param_3 = param_3 + 1;

      uVar5 = uVar5 - 1;

    } while (uVar5 != 0);

  }

  return;

}




