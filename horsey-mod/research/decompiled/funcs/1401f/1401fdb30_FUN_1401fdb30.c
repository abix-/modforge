// Address: 0x1401fdb30
// Ghidra name: FUN_1401fdb30
// ============ 0x1401fdb30 FUN_1401fdb30 (size=585) ============


undefined8 FUN_1401fdb30(longlong param_1,undefined4 *param_2)



{

  longlong lVar1;

  int iVar2;

  undefined4 uVar3;

  longlong lVar4;

  undefined8 uVar5;

  undefined4 uVar6;

  undefined4 *puVar7;

  undefined8 in_stack_ffffffffffffff58;

  undefined8 uVar8;

  undefined8 *puVar9;

  undefined1 local_88 [8];

  undefined8 local_80;

  undefined8 local_68;

  undefined8 local_60;

  undefined8 local_58;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  undefined4 local_44;

  undefined4 local_40;

  undefined4 local_3c;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 uVar10;

  

  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  FUN_1401f9dc0(lVar1);

  if (*(longlong *)(lVar1 + 0x710) != 0) {

    (*DAT_1403fcf10)(*(undefined8 *)(lVar1 + 0x698));

    *(undefined8 *)(lVar1 + 0x710) = 0;

  }

  lVar4 = *(longlong *)(lVar1 + 0x28f8);

  if (lVar4 == 0) {

    uVar6 = *(undefined4 *)(lVar1 + 0x2880);

    uVar5 = *(undefined8 *)

             (*(longlong *)(lVar1 + 0x2898) + (ulonglong)*(uint *)(lVar1 + 0x28c8) * 8);

    puVar7 = (undefined4 *)

             (*(longlong *)(lVar1 + 0x28a8) + (ulonglong)*(uint *)(lVar1 + 0x28c8) * 4);

  }

  else {

    uVar5 = *(undefined8 *)(lVar4 + 8);

    puVar7 = (undefined4 *)(lVar4 + 0x20);

    uVar6 = *(undefined4 *)(lVar4 + 0x24);

  }

  lVar4 = FUN_1401fa4f0(uVar6,0);

  uVar8 = CONCAT44(uVar3,1);

  iVar2 = FUN_1401f58a0(lVar1,(longlong)(int)param_2[3] * lVar4 * (int)param_2[2],2,6,uVar8,local_88

                       );

  if (iVar2 == 0) {

    uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x1000);

    FUN_1401fd560(lVar1,0x19a0,0x800,0x1480,uVar8,6,uVar5,puVar7);

    local_48 = *param_2;

    local_44 = param_2[1];

    local_3c = param_2[2];

    local_38 = param_2[3];

    puVar9 = &local_68;

    local_68 = 0;

    local_60 = 0;

    local_50 = 0;

    local_4c = 1;

    local_58 = 1;

    local_40 = 0;

    local_34 = 1;

    uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),1);

    (*DAT_1403fcf00)(*(undefined8 *)(lVar1 + 0x698),uVar5,*puVar7,local_80,uVar8,puVar9);

    uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);

    uVar10 = (undefined4)((ulonglong)puVar9 >> 0x20);

    FUN_1401fabf0(lVar1);

    FUN_1401fd560(lVar1,0x1000,0x19a0,0x1000,CONCAT44(uVar3,0x1480),CONCAT44(uVar10,2),uVar5,puVar7)

    ;

    uVar3 = FUN_140200070(uVar6);

    uVar5 = FUN_1401460c0(param_2[2],param_2[3],uVar3);

    FUN_1401f98d0(lVar1,local_88);

  }

  else {

    uVar5 = 0;

  }

  return uVar5;

}




