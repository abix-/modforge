// Address: 0x14022fda0
// Ghidra name: FUN_14022fda0
// ============ 0x14022fda0 FUN_14022fda0 (size=172) ============


char * FUN_14022fda0(byte *param_1)



{

  byte bVar1;

  int iVar2;

  size_t sVar3;

  char *pcVar4;

  byte *pbVar5;

  

  iVar2 = strcmp((char *)param_1,"*");

  if (iVar2 == 0) {

    return (char *)0x0;

  }

  bVar1 = *param_1;

  pbVar5 = param_1;

  do {

    if (bVar1 == 0) {

      sVar3 = strlen((char *)param_1);

      pcVar4 = (char *)0x0;

      if (param_1[sVar3 - 1] == 0x3b) {

        pcVar4 = "Empty pattern not allowed";

      }

      return pcVar4;

    }

    if ((0x19 < (byte)(bVar1 + 0x9f)) &&

       ((0x32 < (byte)(bVar1 - 0x2d) ||

        ((0x43ffffff01ffbU >> ((ulonglong)(bVar1 - 0x2d) & 0x3f) & 1) == 0)))) {

      if (bVar1 != 0x3b) {

        return "Invalid character in pattern (Only [a-zA-Z0-9_.-] allowed, or a single *)";

      }

      if ((pbVar5 == param_1) || (pbVar5[-1] == 0x3b)) {

        return "Empty pattern not allowed";

      }

    }

    bVar1 = pbVar5[1];

    pbVar5 = pbVar5 + 1;

  } while( true );

}




