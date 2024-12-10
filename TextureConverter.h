#pragma once
#include <string>
#include "Extemal/DirectXTex/DirectXTex.h"

class TextureConverter
{
private:

	void LoadWICTextureFromFIle(const std::string& filePath);

	std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	/// <summary>
	/// フォルダーパスとファイル名を分離する
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void SeparateFilePath(const std::wstring& filePath);

	// 画像の情報
	DirectX::TexMetadata metadata_;

	// 画像のイメージのコンテナ
	DirectX::ScratchImage scratchImage_;

	// ディレクトリパス
	std::wstring directoryPath_;

	// ファイル名
	std::wstring fileName_;

	// ファイル拡張子
	std::wstring fileExt_;

public:

	/// <summary>
/// テクスチャをWICからDDSに変換
/// </summary>
/// <param name="filePath">ファイルパス</param>
	void ConvertTextureWICToDDS(const std::string& filePath);

};

