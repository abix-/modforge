// Address: 0x1401ac230
// Ghidra name: FUN_1401ac230
// ============ 0x1401ac230 FUN_1401ac230 (size=654) ============


int FUN_1401ac230(longlong param_1,longlong param_2,longlong *param_3)



{

  longlong *plVar1;

  int iVar2;

  int iVar3;

  code *pcVar4;

  int local_res8 [2];

  int local_58 [2];

  ulonglong local_50;

  undefined8 local_48;

  longlong *local_40;

  longlong *local_38;

  longlong *local_30;

  longlong local_28 [2];

  

  iVar3 = 0;

  local_28[0] = 0;

  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x1d0) + 8);

  *(undefined8 *)(*(longlong *)(param_1 + 0x1d0) + 8) = 0;

  iVar2 = FUN_140146bc0(param_2);

  if (iVar2 != 0) {

    (**(code **)(*plVar1 + 0x118))(plVar1,local_28);

    *param_3 = local_28[0] * 100;

  }

  local_40 = (longlong *)0x0;

  iVar2 = (**(code **)(*plVar1 + 0x148))(plVar1,&local_40);

  if (iVar2 < 0) {

    (**(code **)(*plVar1 + 0x10))(plVar1);

    goto LAB_1401ac49f;

  }

  local_30 = (longlong *)0x0;

  local_38 = (longlong *)0x0;

  local_48 = 0;

  local_res8[0] = 0;

  local_58[0] = 0;

  iVar2 = (**(code **)*local_40)(local_40,&DAT_14033caf0,&local_38);

  if (iVar2 < 0) {

    if ((*(int *)(param_2 + 4) != 0x47504a4d) &&

       (iVar2 = (**(code **)*local_40)(local_40,&DAT_14033cae0,&local_30), -1 < iVar2)) {

      iVar2 = (**(code **)(*local_30 + 0x18))(local_30,&local_48,local_res8);

      if (iVar2 < 0) {

        iVar3 = 0;

        pcVar4 = *(code **)(*local_30 + 0x10);

      }

      else {

        iVar2 = *(int *)(param_2 + 0xc);

        local_58[0] = FUN_140190050(local_res8[0]);

        local_58[0] = local_58[0] * iVar2;

        iVar3 = FUN_1401ac520(param_2,local_48,local_res8[0],local_58[0]);

        (**(code **)(*local_30 + 0x20))();

        pcVar4 = *(code **)(*local_30 + 0x10);

      }

      goto LAB_1401ac47e;

    }

    local_50 = local_50 & 0xffffffff00000000;

    iVar2 = (**(code **)(*local_40 + 0x18))(local_40,&local_48,&local_50,local_58);

    if (-1 < iVar2) {

      if (*(int *)(param_2 + 4) == 0x47504a4d) {

        local_res8[0] = local_58[0];

      }

      else {

        local_res8[0] = *(int *)(*(longlong *)(param_1 + 0x1d0) + 0x10);

      }

      iVar3 = FUN_1401ac520(param_2,local_48,local_res8[0]);

      pcVar4 = *(code **)(*local_40 + 0x20);

      goto LAB_1401ac47e;

    }

  }

  else {

    local_50 = 0;

    iVar2 = (**(code **)(*local_38 + 0x50))(local_38,1,&local_48,local_res8,&local_50,local_58);

    if (iVar2 < 0) {

      pcVar4 = *(code **)(*local_38 + 0x10);

    }

    else {

      if (*(int *)(param_2 + 4) == 0x47504a4d) {

        local_res8[0] = local_58[0];

      }

      iVar3 = FUN_1401ac520(param_2,local_48,local_res8[0]);

      (**(code **)(*local_38 + 0x20))();

      pcVar4 = *(code **)(*local_38 + 0x10);

    }

LAB_1401ac47e:

    (*pcVar4)();

  }

  (**(code **)(*local_40 + 0x10))();

  (**(code **)(*plVar1 + 0x10))(plVar1);

  if (iVar3 == 2) {

    return 2;

  }

LAB_1401ac49f:

  *param_3 = 0;

  return iVar3;

}




