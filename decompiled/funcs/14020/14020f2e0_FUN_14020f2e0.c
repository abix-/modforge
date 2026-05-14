// Address: 0x14020f2e0
// Ghidra name: FUN_14020f2e0
// ============ 0x14020f2e0 FUN_14020f2e0 (size=242) ============


undefined8 FUN_14020f2e0(void)



{

  char cVar1;

  int iVar2;

  byte bVar3;

  char *pcVar4;

  undefined4 local_28 [2];

  undefined1 local_20 [24];

  

  local_28[0] = 0;

  cVar1 = FUN_14020f170(&DAT_1403fd330);

  if (cVar1 != '\0') {

    FUN_140179b40(DAT_1403fd320);

    while (DAT_1403fd311 == '\0') {

      cVar1 = FUN_14020f5c0(&DAT_1403fd330,DAT_1403fd320);

      if (cVar1 == '\0') {

        FUN_140163d20(DAT_1403fd318,DAT_1403fd320,1000);

        cVar1 = FUN_1402853c0();

        if (cVar1 != '\0') {

          bVar3 = 0;

          pcVar4 = (char *)local_28;

          do {

            iVar2 = (*DAT_1403fddf8)(bVar3,1,local_20);

            if ((bool)*pcVar4 != (iVar2 == 0)) {

              cVar1 = FUN_14020f650();

              *pcVar4 = cVar1;

            }

            bVar3 = bVar3 + 1;

            pcVar4 = pcVar4 + 1;

          } while (bVar3 < 4);

        }

      }

    }

    FUN_140179b60(DAT_1403fd320);

    FUN_14020f120(&DAT_1403fd330);

    return 1;

  }

  return 0;

}




