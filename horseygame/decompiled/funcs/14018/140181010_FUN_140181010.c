// Address: 0x140181010
// Ghidra name: FUN_140181010
// ============ 0x140181010 FUN_140181010 (size=317) ============


uint FUN_140181010(undefined4 param_1)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  char *_Str2;

  uint uVar6;

  uint uVar7;

  longlong *local_res10;

  undefined8 local_res18 [2];

  undefined1 local_468 [1024];

  char local_68 [80];

  

  cVar1 = FUN_140180d20(local_res18,&local_res10);

  if (cVar1 == '\0') {

    FUN_14012e850("Unable to create Direct3D interface");

    return 0xffffffff;

  }

  lVar4 = FUN_14016d390(param_1);

  if (lVar4 == 0) {

    FUN_14012e850("Invalid display index");

    uVar7 = 0xffffffff;

  }

  else {

    lVar5 = FUN_14012fd40(lVar4);

    _Str2 = (char *)FUN_140197820(&DAT_14039c6f0,"UTF-16LE",lVar4,lVar5 * 2 + 2);

    uVar2 = (**(code **)(*local_res10 + 0x20))();

    uVar6 = 0;

    uVar7 = 0;

    if (uVar2 != 0) {

      do {

        (**(code **)(*local_res10 + 0x28))(local_res10,uVar6,0,local_468);

        iVar3 = strcmp(local_68,_Str2);

        uVar7 = uVar6;

        if (iVar3 == 0) break;

        uVar6 = uVar6 + 1;

        uVar7 = 0;

      } while (uVar6 < uVar2);

    }

    FUN_1401841e0(_Str2);

  }

  (**(code **)(*local_res10 + 0x10))();

  FUN_140188670(local_res18[0]);

  return uVar7;

}




