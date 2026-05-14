// Address: 0x1401795d0
// Ghidra name: FUN_1401795d0
// ============ 0x1401795d0 FUN_1401795d0 (size=177) ============


ulonglong FUN_1401795d0(undefined8 *param_1,char *param_2)



{

  char cVar1;

  byte bVar2;

  longlong lVar3;

  ulonglong uVar4;

  undefined *puVar5;

  undefined1 local_res8 [8];

  

  if (param_1 == (undefined8 *)0x0) {

    puVar5 = &DAT_140335bb8;

  }

  else {

    if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {

      lVar3 = thunk_FUN_1402c9190(param_2,0x3d);

      if (lVar3 == 0) {

        FUN_140179b40(*param_1);

        cVar1 = FUN_1401aaff0(param_1[1],param_2,local_res8);

        if (cVar1 != '\0') {

          bVar2 = FUN_1401ab340(param_1[1],param_2);

          FUN_140179b60(*param_1);

          return (ulonglong)bVar2;

        }

        FUN_140179b60(*param_1);

        return 1;

      }

    }

    puVar5 = &DAT_140304430;

  }

  uVar4 = FUN_14012e850("Parameter \'%s\' is invalid",puVar5);

  return uVar4;

}




