#pragma once
#include <string>
class TextureConverter
{
private:

	void LoadWICTextureFromFIle(const std::string& filePath);


	std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	/// <summary>
	/// テクスチャをWICからDDSに変換
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void ConvertTextureWICToDDS(const std::string& filePath);

public:

};

