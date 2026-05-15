// Address: 0x140288540
// Ghidra name: FUN_140288540
// ============ 0x140288540 FUN_140288540 (size=348) ============


ulonglong FUN_140288540(longlong param_1,longlong param_2,undefined2 *param_3)



{

  longlong *plVar1;

  char cVar2;

  undefined4 uVar3;

  int iVar4;

  ulonglong uVar5;

  undefined8 *puVar6;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 uStack_10;

  

  local_58 = 0;

  uStack_50 = 0;

  local_48 = 0;

  uStack_40 = 0;

  local_38 = 0;

  uStack_30 = 0;

  local_28 = 0;

  uStack_20 = 0;

  local_18 = 0;

  uStack_10 = 0;

  cVar2 = FUN_1402889b0(0,&local_58);

  if (cVar2 == '\0') goto LAB_140288677;

  uVar3 = FUN_140287450(*(undefined8 *)(param_2 + 0x48),&local_58);

  plVar1 = *(longlong **)(*(longlong *)(param_2 + 0x48) + 0x50);

  iVar4 = (**(code **)(*plVar1 + 0x30))(plVar1,&local_58,uVar3);

  puVar6 = (undefined8 *)(param_1 + 0x28);

  if (iVar4 == -0x7ffbfdfb) {

    (**(code **)(**(longlong **)*puVar6 + 0x40))();

    iVar4 = (**(code **)(**(longlong **)*puVar6 + 0x68))(*(longlong **)*puVar6,DAT_1403fcd60,9);

    if (iVar4 < 0) goto LAB_1402885ea;

LAB_1402885f8:

    iVar4 = (**(code **)(**(longlong **)*puVar6 + 0x38))();

    if (-1 < iVar4) {

      plVar1 = *(longlong **)(*(longlong *)(param_2 + 0x48) + 0x50);

      iVar4 = (**(code **)(*plVar1 + 0x30))(plVar1,&local_58,uVar3);

      goto LAB_140288625;

    }

  }

  else {

LAB_1402885ea:

    if ((iVar4 == -0x7ff8ffe2) || (iVar4 == -0x7ff8fff4)) goto LAB_1402885f8;

LAB_140288625:

    if (-1 < iVar4) {

      FUN_140288830(*(undefined8 *)(param_2 + 0x48),*param_3);

      puVar6 = *(undefined8 **)(param_2 + 0x48);

      *puVar6 = local_58;

      puVar6[1] = uStack_50;

      puVar6[2] = local_48;

      puVar6[3] = uStack_40;

      puVar6[4] = local_38;

      puVar6[5] = uStack_30;

      puVar6[6] = local_28;

      puVar6[7] = uStack_20;

      puVar6[8] = local_18;

      puVar6[9] = uStack_10;

      return CONCAT71((int7)((ulonglong)puVar6 >> 8),1);

    }

  }

  FUN_1402878d0("Unable to update effect",iVar4);

LAB_140288677:

  uVar5 = FUN_140288830(&local_58,*param_3);

  return uVar5 & 0xffffffffffffff00;

}




