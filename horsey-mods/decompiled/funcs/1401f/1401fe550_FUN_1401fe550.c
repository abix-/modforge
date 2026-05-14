// Address: 0x1401fe550
// Ghidra name: FUN_1401fe550
// ============ 0x1401fe550 FUN_1401fe550 (size=643) ============


undefined8 FUN_1401fe550(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)



{

  undefined4 *puVar1;

  longlong lVar2;

  longlong lVar3;

  undefined8 uVar4;

  longlong lVar5;

  longlong lVar6;

  bool bVar7;

  undefined8 in_stack_ffffffffffffff38;

  undefined4 uVar9;

  undefined8 uVar8;

  undefined8 in_stack_ffffffffffffff48;

  undefined4 uVar10;

  undefined8 local_88;

  undefined8 local_80;

  longlong local_78;

  longlong local_70;

  undefined1 local_68 [48];

  

  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);

  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);

  puVar1 = *(undefined4 **)(param_2 + 0x30);

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  lVar3 = *(longlong *)(puVar1 + 0x4e);

  lVar6 = *(longlong *)(lVar3 + 0x88);

  if (lVar6 == 0) {

    lVar6 = *(longlong *)(lVar2 + 0x748);

  }

  lVar5 = *(longlong *)(lVar3 + 0x90);

  if (lVar5 == 0) {

    lVar5 = *(longlong *)(lVar2 + 0x750);

  }

  FUN_1401fedf0(param_1,param_2,puVar1,local_68);

  if (*(int *)(lVar3 + 0x20) != 5) {

    bVar7 = *(longlong *)(lVar2 + 0x710) != 0;

    if (bVar7) {

      (*DAT_1403fcf10)(*(undefined8 *)(lVar2 + 0x698));

      *(undefined8 *)(lVar2 + 0x710) = 0;

    }

    uVar4 = *(undefined8 *)(lVar3 + 8);

    uVar8 = CONCAT44(uVar9,0x80);

    FUN_1401fd560(lVar2,0x11a0,0x20,0x1480,uVar8,5,uVar4,lVar3 + 0x20);

    uVar10 = (undefined4)((ulonglong)uVar4 >> 0x20);

    uVar9 = (undefined4)((ulonglong)uVar8 >> 0x20);

    if (bVar7) {

      FUN_1401f6480(lVar2,0,0);

    }

  }

  local_88 = *(undefined8 *)(lVar3 + 0x10);

  uVar4 = CONCAT44(uVar9,*(undefined4 *)(param_2 + 0x40));

  local_78 = FUN_1401fa5f0(lVar2,*puVar1,*(undefined4 *)(param_2 + 0x38),

                           *(undefined4 *)(param_2 + 0x3c),uVar4);

  uVar9 = (undefined4)((ulonglong)uVar4 >> 0x20);

  if (local_78 == 0) {

LAB_1401fe73b:

    uVar4 = 0;

  }

  else {

    if (*(longlong *)(puVar1 + 0x38) == 0) {

      local_80 = local_88;

      local_70 = local_78;

    }

    else {

      lVar3 = *(longlong *)(*(longlong *)(puVar1 + 0x38) + 0x10);

      if (*(int *)(lVar3 + 0x20) != 5) {

        bVar7 = *(longlong *)(lVar2 + 0x710) != 0;

        if (bVar7) {

          (*DAT_1403fcf10)(*(undefined8 *)(lVar2 + 0x698));

          *(undefined8 *)(lVar2 + 0x710) = 0;

        }

        uVar4 = *(undefined8 *)(lVar3 + 8);

        uVar8 = CONCAT44(uVar9,0x80);

        FUN_1401fd560(lVar2,0x11a0,0x20,0x1480,uVar8,5,uVar4,lVar3 + 0x20);

        uVar10 = (undefined4)((ulonglong)uVar4 >> 0x20);

        uVar9 = (undefined4)((ulonglong)uVar8 >> 0x20);

        if (bVar7) {

          FUN_1401f6480(lVar2,0,0);

        }

      }

      local_80 = *(undefined8 *)(lVar3 + 0x10);

      local_70 = FUN_1401fa5f0(lVar2,0,0,1,CONCAT44(uVar9,1));

      if (local_70 == 0) goto LAB_1401fe73b;

    }

    uVar4 = FUN_1401fe7e0(param_1,param_2,lVar5,lVar6,local_68,3,CONCAT44(uVar10,2),&local_88,2,

                          &local_78,param_3,param_4);

  }

  return uVar4;

}




