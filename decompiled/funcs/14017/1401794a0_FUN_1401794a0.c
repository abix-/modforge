// Address: 0x1401794a0
// Ghidra name: FUN_1401794a0
// ============ 0x1401794a0 FUN_1401794a0 (size=304) ============


ulonglong FUN_1401794a0(undefined8 *param_1,char *param_2,longlong param_3,char param_4)



{

  byte bVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  size_t sVar5;

  ulonglong uVar6;

  char *pcVar7;

  longlong local_res8;

  undefined8 local_28 [2];

  

  bVar1 = 0;

  if (param_1 == (undefined8 *)0x0) {

    pcVar7 = "env";

  }

  else if (((param_2 == (char *)0x0) || (*param_2 == '\0')) ||

          (lVar4 = thunk_FUN_1402c9190(param_2,0x3d), lVar4 != 0)) {

    pcVar7 = "name";

  }

  else {

    if (param_3 != 0) {

      FUN_140179b40(*param_1);

      local_res8 = 0;

      iVar3 = FUN_14012ee40(&local_res8,"%s=%s",param_2,param_3);

      if (0 < iVar3) {

        sVar5 = strlen(param_2);

        *(undefined1 *)(sVar5 + local_res8) = 0;

        bVar1 = FUN_1401ab100(param_1[1],local_res8,local_res8 + 1 + sVar5,param_4);

        if ((bVar1 == 0) && (FUN_1401841e0(local_res8), param_4 == '\0')) {

          local_28[0] = 0;

          cVar2 = FUN_1401aaff0(param_1[1],param_2,local_28);

          if (cVar2 != '\0') {

            bVar1 = 1;

          }

        }

      }

      FUN_140179b60(*param_1);

      return (ulonglong)bVar1;

    }

    pcVar7 = "value";

  }

  uVar6 = FUN_14012e850("Parameter \'%s\' is invalid",pcVar7);

  return uVar6;

}




