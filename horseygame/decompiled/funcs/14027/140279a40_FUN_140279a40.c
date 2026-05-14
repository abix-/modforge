// Address: 0x140279a40
// Ghidra name: FUN_140279a40
// ============ 0x140279a40 FUN_140279a40 (size=202) ============


ulonglong FUN_140279a40(longlong param_1)



{

  undefined8 uVar1;

  char cVar2;

  char cVar3;

  ulonglong uVar4;

  int iVar5;

  ushort uVar6;

  ushort local_res8 [4];

  

  uVar1 = *(undefined8 *)(param_1 + 0x70);

  iVar5 = 0;

  do {

    cVar2 = FUN_140279d40(uVar1,1);

    if (cVar2 != '\0') {

      cVar2 = FUN_1402796b0(uVar1,local_res8);

      uVar6 = local_res8[0];

      if (cVar2 != '\0') {

        cVar2 = '\0';

        if ((((local_res8[0] & 0xf0ff) == 5) && (cVar2 = (char)(local_res8[0] >> 8), cVar2 != '\0'))

           || (local_res8[0] == 0xffff)) {

          FUN_140279d60(uVar1,1);

          cVar3 = FUN_140279d40(uVar1,1);

          if (cVar3 != '\0') {

            FUN_1402796b0(uVar1,local_res8);

            uVar6 = local_res8[0];

          }

        }

        uVar4 = FUN_140278720(uVar6);

        if (cVar2 != '\0') {

          FUN_1402785a0(uVar1,cVar2);

          uVar4 = uVar4 & 0xffffffff;

        }

        return uVar4;

      }

    }

    iVar5 = iVar5 + 1;

  } while (iVar5 < 0x14);

  return 0;

}




