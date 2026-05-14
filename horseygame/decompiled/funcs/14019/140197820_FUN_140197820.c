// Address: 0x140197820
// Ghidra name: FUN_140197820
// ============ 0x140197820 FUN_140197820 (size=407) ============


undefined4 * FUN_140197820(char *param_1,char *param_2,longlong param_3,longlong param_4)



{

  undefined4 *puVar1;

  longlong lVar2;

  longlong lVar3;

  undefined4 *puVar4;

  longlong lVar5;

  bool bVar6;

  undefined4 *local_res8;

  longlong local_res10;

  longlong local_res18;

  longlong local_res20;

  

  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {

    param_1 = "UTF-8";

  }

  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {

    param_2 = "UTF-8";

  }

  local_res18 = param_3;

  local_res20 = param_4;

  lVar2 = FUN_140197730(param_1,param_2);

  if (lVar2 == -1) {

    return (undefined4 *)0x0;

  }

  local_res8 = (undefined4 *)FUN_1401841f0();

  if (local_res8 == (undefined4 *)0x0) {

    FUN_140197710(lVar2);

    return (undefined4 *)0x0;

  }

  *local_res8 = 0;

  puVar1 = local_res8;

  local_res10 = param_4;

  lVar5 = param_4;

joined_r0x0001401978be:

  do {

    if (lVar5 == 0) goto LAB_140197978;

    lVar3 = FUN_140196db0(lVar2,&local_res18,&local_res20,&local_res8,&local_res10);

    if (lVar3 == -4) {

LAB_140197963:

      local_res20 = 0;

    }

    else if (lVar3 == -3) {

      local_res18 = local_res18 + 1;

      local_res20 = local_res20 + -1;

    }

    else {

      if (lVar3 == -2) {

        param_4 = param_4 * 2;

        lVar5 = (longlong)local_res8 - (longlong)puVar1;

        puVar4 = (undefined4 *)FUN_140184230(puVar1,param_4 + 4);

        if (puVar4 == (undefined4 *)0x0) {

          FUN_1401841e0(puVar1);

          FUN_140197710(lVar2);

          return (undefined4 *)0x0;

        }

        local_res8 = (undefined4 *)(lVar5 + (longlong)puVar4);

        local_res10 = param_4 - lVar5;

        *local_res8 = 0;

        puVar1 = puVar4;

        lVar5 = local_res20;

        goto joined_r0x0001401978be;

      }

      if (lVar3 == -1) goto LAB_140197963;

    }

    bVar6 = lVar5 == local_res20;

    lVar5 = local_res20;

    if (bVar6) {

LAB_140197978:

      *local_res8 = 0;

      FUN_140197710(lVar2);

      return puVar1;

    }

  } while( true );

}




