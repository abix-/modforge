// Address: 0x1400297b0
// Ghidra name: FUN_1400297b0
// ============ 0x1400297b0 FUN_1400297b0 (size=728) ============


undefined8 * FUN_1400297b0(undefined8 param_1,undefined8 param_2,undefined4 param_3)



{

  int iVar1;

  int iVar2;

  char *pcVar3;

  undefined8 *puVar4;

  undefined8 uVar5;

  char *pcVar6;

  

  pcVar3 = (char *)FUN_140028820(param_2,param_3);

  if ((((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) || (*pcVar3 != '<')) ||

     ((pcVar3 = (char *)FUN_140028820(pcVar3,param_3), pcVar3 == (char *)0x0 || (*pcVar3 == '\0'))))

  {

    return (undefined8 *)0x0;

  }

  pcVar6 = "<?xml";

  do {

    if (*pcVar6 == '\0') goto LAB_140029a4b;

    iVar1 = tolower((int)pcVar6[(longlong)(pcVar3 + -0x14039c754)]);

    iVar2 = tolower((int)*pcVar6);

  } while ((iVar1 == iVar2) &&

          (pcVar6 = pcVar6 + 1, (pcVar3 + -0x14039c754)[(longlong)pcVar6] != '\0'));

  if (*pcVar6 == '\0') {

LAB_140029a4b:

    uVar5 = FUN_1402c704c(200);

    puVar4 = (undefined8 *)FUN_140024b40(uVar5);

    goto LAB_140029a62;

  }

  pcVar6 = "<!--";

  if (*pcVar3 == '\0') {

    FID_conflict__assert(L"0",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21f);

  }

  else {

    do {

      if (*pcVar6 == '\0') goto LAB_14002988a;

    } while ((pcVar6[(longlong)(pcVar3 + -0x14039c098)] == *pcVar6) &&

            (pcVar6 = pcVar6 + 1, (pcVar3 + -0x14039c098)[(longlong)pcVar6] != '\0'));

    if (*pcVar6 == '\0') {

LAB_14002988a:

      puVar4 = (undefined8 *)FUN_1402c704c();

      puVar4[1] = 0xffffffffffffffff;

      puVar4[2] = 0;

      puVar4[7] = 0;

      puVar4[8] = 0;

      puVar4[9] = 0;

      puVar4[10] = 0xf;

      *(undefined1 *)(puVar4 + 7) = 0;

      puVar4[3] = 0;

      *(undefined4 *)(puVar4 + 4) = 2;

      puVar4[5] = 0;

      puVar4[6] = 0;

      puVar4[0xb] = 0;

      puVar4[0xc] = 0;

      *puVar4 = TiXmlComment::vftable;

      goto LAB_140029a62;

    }

  }

  pcVar6 = "<![CDATA[";

  if (*pcVar3 == '\0') {

    FID_conflict__assert(L"0",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21f);

  }

  else {

    do {

      if (*pcVar6 == '\0') goto LAB_14002992d;

    } while (((pcVar3 + -0x14039c088)[(longlong)pcVar6] == *pcVar6) &&

            (pcVar6 = pcVar6 + 1, (pcVar3 + -0x14039c088)[(longlong)pcVar6] != '\0'));

    if (*pcVar6 == '\0') {

LAB_14002992d:

      uVar5 = FUN_1402c704c(0x70);

      puVar4 = (undefined8 *)FUN_1400249e0(uVar5);

      *(undefined1 *)(puVar4 + 0xd) = 1;

      goto LAB_140029a62;

    }

  }

  pcVar6 = "<!";

  if (*pcVar3 == '\0') {

    FID_conflict__assert(L"0",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21f);

LAB_140029a0d:

    if (((0x7e < (byte)pcVar3[1]) || (iVar1 = isalpha((uint)(byte)pcVar3[1]), iVar1 != 0)) ||

       (pcVar3[1] == '_')) {

      uVar5 = FUN_1402c704c(0xd8);

      puVar4 = (undefined8 *)FUN_140025490(uVar5,&DAT_14039bcb9);

      goto LAB_140029a62;

    }

  }

  else {

    do {

      if (*pcVar6 == '\0') goto LAB_14002999a;

    } while ((pcVar6[(longlong)(pcVar3 + -0x14039c75c)] == *pcVar6) &&

            (pcVar6 = pcVar6 + 1, (pcVar3 + -0x14039c75c)[(longlong)pcVar6] != '\0'));

    if (*pcVar6 != '\0') goto LAB_140029a0d;

  }

LAB_14002999a:

  puVar4 = (undefined8 *)FUN_1402c704c();

  puVar4[1] = 0xffffffffffffffff;

  puVar4[2] = 0;

  puVar4[7] = 0;

  puVar4[8] = 0;

  puVar4[9] = 0;

  puVar4[10] = 0xf;

  *(undefined1 *)(puVar4 + 7) = 0;

  puVar4[3] = 0;

  *(undefined4 *)(puVar4 + 4) = 3;

  puVar4[5] = 0;

  puVar4[6] = 0;

  puVar4[0xb] = 0;

  puVar4[0xc] = 0;

  *puVar4 = TiXmlUnknown::vftable;

LAB_140029a62:

  if (puVar4 == (undefined8 *)0x0) {

    return (undefined8 *)0x0;

  }

  puVar4[3] = param_1;

  return puVar4;

}




