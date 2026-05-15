// Address: 0x14021b680
// Ghidra name: FUN_14021b680
// ============ 0x14021b680 FUN_14021b680 (size=656) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14021b680(undefined8 param_1,longlong param_2,longlong *param_3)



{

  float fVar1;

  BOOL BVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  int iVar6;

  longlong lVar7;

  longlong *plVar8;

  longlong lVar9;

  _FILETIME local_res20;

  float local_98;

  float local_94;

  float local_90;

  SYSTEMTIME local_88;

  undefined8 local_78;

  double dStack_70;

  undefined8 local_68;

  undefined8 local_60;

  double dStack_58;

  undefined8 local_50;

  undefined8 local_48;

  double dStack_40;

  undefined8 local_38;

  

  lVar5 = FUN_140149300();

  FUN_140177410();

  iVar6 = 0;

  if (0 < DAT_1403fdb90) {

    plVar8 = (longlong *)(DAT_1403fdb98 + 8);

    do {

      if (param_2 == *plVar8) {

        lVar7 = (longlong)iVar6 * 0x38;

        if (*(longlong *)(lVar7 + 0x30 + DAT_1403fdb98) == 0) break;

        local_68 = 0;

        local_50 = 0;

        local_38 = 0;

        local_78 = 0;

        dStack_70 = 0.0;

        local_60 = 0;

        dStack_58 = 0.0;

        local_48 = 0;

        dStack_40 = 0.0;

        iVar6 = (**(code **)(*param_3 + 0x18))(param_3,&local_88);

        lVar9 = lVar5;

        if ((-1 < iVar6) && (BVar2 = SystemTimeToFileTime(&local_88,&local_res20), BVar2 != 0)) {

          lVar9 = (longlong)local_res20 * 100;

        }

        iVar6 = *(int *)(lVar7 + 0x28 + DAT_1403fdb98);

        if (iVar6 == 1) {

          iVar6 = (**(code **)(*param_3 + 0x20))(param_3,&DAT_140355270,&local_78);

          iVar3 = (**(code **)(*param_3 + 0x20))(param_3,&DAT_140355288,&local_60);

          iVar4 = (**(code **)(*param_3 + 0x20))(param_3,&DAT_1403552a0,&local_48);

          if ((((iVar6 < 0) || (iVar3 < 0)) || (iVar4 < 0)) ||

             (((short)local_78 != 5 || ((short)local_60 != 5)))) break;

          fVar1 = _DAT_1403553cc;

        }

        else {

          if (iVar6 != 2) break;

          iVar6 = (**(code **)(*param_3 + 0x20))(param_3,&DAT_1403552f8,&local_78);

          iVar3 = (**(code **)(*param_3 + 0x20))(param_3,&DAT_140355310,&local_60);

          iVar4 = (**(code **)(*param_3 + 0x20))(param_3,&DAT_140355328,&local_48);

          if (((iVar6 < 0) || (iVar3 < 0)) ||

             ((iVar4 < 0 || (((short)local_78 != 5 || ((short)local_60 != 5)))))) break;

          fVar1 = DAT_14030d930;

        }

        if ((short)local_48 == 5) {

          local_98 = (float)dStack_70 * fVar1;

          local_90 = (float)dStack_40 * fVar1;

          local_94 = (float)dStack_58 * fVar1;

          FUN_140177630(lVar5,*(undefined8 *)(lVar7 + 0x30 + DAT_1403fdb98),lVar9,&local_98,3);

        }

        break;

      }

      iVar6 = iVar6 + 1;

      plVar8 = plVar8 + 7;

    } while (iVar6 < DAT_1403fdb90);

  }

  FUN_140177750();

  return 0;

}




