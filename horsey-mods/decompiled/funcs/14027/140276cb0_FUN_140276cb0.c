// Address: 0x140276cb0
// Ghidra name: FUN_140276cb0
// ============ 0x140276cb0 FUN_140276cb0 (size=515) ============


/* WARNING: Type propagation algorithm not settling */



undefined8 FUN_140276cb0(undefined8 param_1,char param_2,undefined4 *param_3)



{

  int iVar1;

  char *pcVar2;

  undefined4 uVar3;

  ulonglong uVar4;

  undefined1 local_68;

  char cStack_67;

  byte bStack_66;

  char cStack_65;

  undefined1 auStack_64 [7];

  undefined4 uStack_5d;

  undefined1 uStack_59;

  undefined7 uStack_58;

  undefined1 uStack_51;

  undefined7 uStack_50;

  undefined1 uStack_49;

  undefined7 local_48;

  undefined1 uStack_41;

  undefined7 uStack_40;

  undefined1 uStack_39;

  undefined7 uStack_38;

  undefined1 uStack_31;

  undefined7 uStack_30;

  undefined1 uStack_29;

  undefined1 local_28;

  

  local_68 = 0;

  bStack_66 = 0;

  _cStack_65 = 0;

  auStack_64._3_4_ = 0;

  uStack_5d = 0;

  uStack_59 = 0;

  cStack_67 = -0x7d;

  local_28 = 0;

  uVar3 = 9000;

  uStack_58 = 0;

  uStack_51 = 0;

  uStack_50 = 0;

  uStack_49 = 0;

  local_48 = 0;

  uStack_41 = 0;

  uStack_40 = 0;

  uStack_39 = 0;

  uStack_38 = 0;

  uStack_31 = 0;

  uStack_30 = 0;

  uStack_29 = 0;

  iVar1 = FUN_140277070(0,&local_68,2);

  if (iVar1 < 0) {

    if (param_2 != '\0') {

      return 0;

    }

    pcVar2 = "GET_ATTRIBUTES_VALUES failed for controller %p\n";

  }

  else {

    iVar1 = FUN_140276bb0(param_1,&local_68,0x83);

    if (((iVar1 < 0) || (cStack_67 != -0x7d)) || (iVar1 < (int)(uint)bStack_66)) {

      if (param_2 != '\0') {

        return 0;

      }

      pcVar2 = "Bad GET_ATTRIBUTES_VALUES response for controller %p\n";

    }

    else {

      uVar4 = 0;

      if ((ulonglong)bStack_66 / 5 != 0) {

        do {

          if ((&cStack_65)[uVar4 * 5] == '\v') {

            uVar3 = *(undefined4 *)(auStack_64 + uVar4 * 5);

          }

          uVar4 = (ulonglong)((int)uVar4 + 1);

        } while (uVar4 < (ulonglong)bStack_66 / 5);

      }

      if (param_3 != (undefined4 *)0x0) {

        *param_3 = uVar3;

      }

      local_68 = 0;

      bStack_66 = 0;

      _cStack_65 = 0;

      auStack_64._3_4_ = 0;

      uStack_5d = 0;

      uStack_59 = 0;

      cStack_67 = -0x7f;

      uStack_58 = 0;

      uStack_51 = 0;

      uStack_50 = 0;

      uStack_49 = 0;

      local_28 = 0;

      local_48 = 0;

      uStack_41 = 0;

      uStack_40 = 0;

      uStack_39 = 0;

      uStack_38 = 0;

      uStack_31 = 0;

      uStack_30 = 0;

      uStack_29 = 0;

      iVar1 = FUN_140277070(param_1,&local_68,2);

      if (iVar1 < 0) {

        if (param_2 != '\0') {

          return 0;

        }

        pcVar2 = "CLEAR_DIGITAL_MAPPINGS failed for controller %p\n";

      }

      else {

        local_68 = 0;

        _cStack_65 = 0;

        auStack_64._3_4_ = 0;

        uStack_5d = 0;

        uStack_59 = 0;

        cStack_67 = -0x72;

        bStack_66 = 0;

        uStack_58 = 0;

        uStack_51 = 0;

        uStack_50 = 0;

        uStack_49 = 0;

        local_28 = 0;

        local_48 = 0;

        uStack_41 = 0;

        uStack_40 = 0;

        uStack_39 = 0;

        uStack_38 = 0;

        uStack_31 = 0;

        uStack_30 = 0;

        uStack_29 = 0;

        iVar1 = FUN_140277070(param_1,&local_68,3);

        if (iVar1 < 0) {

          if (param_2 != '\0') {

            return 0;

          }

          pcVar2 = "LOAD_DEFAULT_SETTINGS failed for controller %p\n";

        }

        else {

          local_68 = 0;

          cStack_67 = -0x79;

          uStack_59 = 0;

          uStack_58 = 0;

          uStack_51 = 0;

          uStack_50 = 0;

          uStack_49 = 0;

          local_48 = 0;

          uStack_41 = 0;

          uStack_40 = 0;

          uStack_39 = 0;

          uStack_38 = 0;

          uStack_31 = 0;

          uStack_30 = 0;

          uStack_29 = 0;

          local_28 = 0;

          _cStack_65 = 0x7000231;

          auStack_64._3_4_ = 0x7080007;

          uStack_5d = 0x1800;

          bStack_66 = 0xc;

          iVar1 = FUN_140277070(param_1,&local_68,0xf);

          if (-1 < iVar1) {

            return 1;

          }

          if (param_2 != '\0') {

            return 0;

          }

          pcVar2 = "SET_SETTINGS failed for controller %p\n";

        }

      }

    }

  }

  FUN_14012e310(pcVar2,param_1);

  return 0;

}




