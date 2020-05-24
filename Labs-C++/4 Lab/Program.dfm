object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Lab4V1 (by Nemkovich)'
  ClientHeight = 197
  ClientWidth = 331
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 316
    Height = 15
    Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1080#1088#1086#1074#1072#1085#1080#1077' '#1089' '#1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1085#1080#1077#1084' '#1089#1090#1101#1082#1072' ( Lab 4, v 1 )'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 152
    Width = 169
    Height = 13
    Caption = 'Variable values ( keyboard input! ):'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsItalic, fsUnderline]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 43
    Width = 88
    Height = 13
    Caption = 'Enter the formula:'
  end
  object Label4: TLabel
    Left = 11
    Top = 171
    Width = 6
    Height = 16
    Caption = 'a'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 79
    Top = 171
    Width = 7
    Height = 16
    Caption = 'b'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 143
    Top = 171
    Width = 7
    Height = 16
    Caption = 'c'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 210
    Top = 171
    Width = 7
    Height = 16
    Caption = 'd'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label8: TLabel
    Left = 270
    Top = 171
    Width = 6
    Height = 16
    Caption = 'e'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label9: TLabel
    Left = 8
    Top = 24
    Width = 139
    Height = 10
    Caption = '(Remember to enter the numbers below!)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -8
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 108
    Top = 40
    Width = 215
    Height = 21
    TabOrder = 0
    TextHint = 'Formula'
  end
  object Edit2: TEdit
    Left = 8
    Top = 98
    Width = 315
    Height = 21
    ReadOnly = True
    TabOrder = 1
    Text = 'Polish entry'
  end
  object Edit3: TEdit
    Left = 8
    Top = 125
    Width = 315
    Height = 21
    ReadOnly = True
    TabOrder = 2
    Text = 'Result'
  end
  object Button1: TButton
    Left = 8
    Top = 67
    Width = 315
    Height = 25
    Caption = 'Display the Polish entry and calculate'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Edit4: TEdit
    Left = 23
    Top = 171
    Width = 41
    Height = 21
    TabOrder = 4
    Text = '8,6'
  end
  object Edit5: TEdit
    Left = 92
    Top = 171
    Width = 41
    Height = 21
    TabOrder = 5
    Text = '2,4'
  end
  object Edit6: TEdit
    Left = 156
    Top = 171
    Width = 41
    Height = 21
    TabOrder = 6
    Text = '5,1'
  end
  object Edit7: TEdit
    Left = 223
    Top = 171
    Width = 41
    Height = 21
    TabOrder = 7
    Text = '0,3'
  end
  object Edit8: TEdit
    Left = 282
    Top = 171
    Width = 41
    Height = 21
    TabOrder = 8
    Text = '7,9'
  end
end
