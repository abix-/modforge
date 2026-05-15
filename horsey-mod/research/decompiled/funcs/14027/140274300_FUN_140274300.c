// Address: 0x140274300
// Ghidra name: FUN_140274300
// ============ 0x140274300 FUN_140274300 (size=329) ============


undefined8 FUN_140274300(longlong *param_1,uint param_2,undefined1 param_3)



{

  byte bVar1;

  undefined8 uVar2;

  byte bVar3;

  byte bVar4;

  ulonglong uVar5;

  bool bVar6;

  undefined8 local_38;

  ulonglong uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  uint local_10;

  undefined2 local_c;

  undefined1 local_a;

  

  uVar5 = (ulonglong)param_2;

  if ((((*(char *)(*param_1 + 0x54) != '\0') && ((char)param_1[4] != '\0')) &&

      ((param_2 & 0x18) != 0)) && (*(int *)((longlong)param_1 + 0x74) != 2)) {

    *(undefined4 *)((longlong)param_1 + 0x74) = 1;

    return CONCAT71((int7)((ulonglong)*param_1 >> 8),1);

  }

  bVar1 = 0;

  local_38 = 0;

  uStack_30 = 0;

  local_18 = 0;

  local_28 = 0;

  uStack_20 = 0;

  local_10 = 0;

  local_c = 0;

  local_a = 0;

  if (*(char *)((longlong)param_1 + 0x14) != '\0') {

    bVar3 = *(byte *)((longlong)param_1 + 0x6e);

    if ((bVar3 != 0) || (*(char *)((longlong)param_1 + 0x6f) != '\0')) {

      bVar6 = *(char *)((longlong)param_1 + 0x6d) == '\0';

      bVar4 = *(byte *)((longlong)param_1 + 0x6f);

      if (bVar6) {

        bVar3 = bVar3 >> 1;

        bVar4 = bVar4 >> 1;

      }

      else {

        local_18 = 0x4000000000000;

      }

      bVar1 = bVar6 | 2;

      local_38 = (ulonglong)bVar4 << 0x10;

      local_38 = (ulonglong)CONCAT13(bVar3,(int3)CONCAT71(local_38._1_7_,bVar6)) | 2;

    }

    if ((param_2 & 1) != 0) {

      local_38 = CONCAT71(local_38._1_7_,bVar1) | 2;

    }

  }

  if (*(char *)((longlong)param_1 + 0x13) != '\0') {

    if ((param_2 & 4) != 0) {

      local_38._0_2_ = CONCAT11(8,(undefined1)local_38);

    }

    if ((param_2 & 8) != 0) {

      local_38 = local_38 | 0x400;

      if ((char)param_1[0xe] == '\0') {

        FUN_140274560(&local_38,(int)param_1[0xd]);

      }

      else {

        local_c = *(undefined2 *)((longlong)param_1 + 0x71);

        local_a = *(undefined1 *)((longlong)param_1 + 0x73);

      }

    }

  }

  if ((*(char *)((longlong)param_1 + 0x15) != '\0') && ((uVar5 & 0x10) != 0)) {

    local_38 = local_38 | 0x1000;

    if (*(char *)((longlong)param_1 + 0x6c) == '\0') {

      local_10 = local_10 & 0xffffff;

    }

    else {

      FUN_1402745c0(&local_38,(int)param_1[0xd]);

    }

  }

  if ((uVar5 & 0x20) != 0) {

    local_38 = local_38 | 0x100;

    uStack_30 = uStack_30 & 0xffffffffffffff00;

  }

  uVar2 = FUN_140273a10(param_1,&local_38,0x2f,param_3);

  return uVar2;

}




