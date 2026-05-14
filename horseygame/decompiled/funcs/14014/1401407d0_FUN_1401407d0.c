// Address: 0x1401407d0
// Ghidra name: FUN_1401407d0
// ============ 0x1401407d0 FUN_1401407d0 (size=394) ============


longlong FUN_1401407d0(undefined4 *param_1,char param_2)



{

  char cVar1;

  longlong lVar2;

  longlong lVar3;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  local_18 = *param_1;

  uStack_14 = param_1[1];

  uStack_10 = param_1[2];

  uStack_c = param_1[3];

  lVar2 = FUN_140140c20(&local_18,1);

  if (lVar2 == 0) {

    if (param_2 != '\0') {

      return 0;

    }

    local_18 = *param_1;

    uStack_14 = param_1[1];

    uStack_10 = param_1[2];

    uStack_c = param_1[3];

    lVar2 = FUN_140140c20(&local_18,1,0);

    if (lVar2 == 0) {

      local_18 = *param_1;

      uStack_14 = param_1[1];

      uStack_10 = param_1[2];

      uStack_c = param_1[3];

      cVar1 = FUN_140159940(&local_18);

      if (cVar1 != '\0') {

        local_18 = *param_1;

        uStack_14 = param_1[1];

        uStack_10 = param_1[2];

        uStack_c = param_1[3];

        lVar2 = FUN_140140c20(&local_18,0,1);

        if (lVar2 != 0) {

          return lVar2;

        }

        local_18 = *param_1;

        uStack_14 = param_1[1];

        uStack_10 = param_1[2];

        uStack_c = param_1[3];

        lVar3 = FUN_140140c20(&local_18,0,0);

        lVar2 = 0;

        if (lVar3 != 0) {

          return lVar3;

        }

      }

      local_18 = *param_1;

      uStack_14 = param_1[1];

      uStack_10 = param_1[2];

      uStack_c = param_1[3];

      cVar1 = FUN_140159790(&local_18);

      if (cVar1 != '\0') {

        return DAT_1403fbf28;

      }

      local_18 = *param_1;

      uStack_14 = param_1[1];

      uStack_10 = param_1[2];

      uStack_c = param_1[3];

      cVar1 = FUN_1401594b0(&local_18);

      local_18 = *param_1;

      uStack_14 = param_1[1];

      uStack_10 = param_1[2];

      uStack_c = param_1[3];

      if (cVar1 != '\0') {

        lVar2 = FUN_14013cd50();

        return lVar2;

      }

      cVar1 = FUN_140159600(&local_18);

      local_18 = *param_1;

      uStack_14 = param_1[1];

      uStack_10 = param_1[2];

      uStack_c = param_1[3];

      if (cVar1 != '\0') {

        lVar2 = FUN_14013d470();

        return lVar2;

      }

      cVar1 = FUN_140159770(&local_18);

      local_18 = *param_1;

      uStack_14 = param_1[1];

      uStack_10 = param_1[2];

      uStack_c = param_1[3];

      if (cVar1 != '\0') {

        lVar2 = FUN_14013d4e0();

        return lVar2;

      }

      FUN_1401596e0(&local_18);

    }

  }

  return lVar2;

}




