class Nocol < Formula
  desc "Terminal client for Chat GPT"
  homepage "https://github.com/divanvisagie/nocol"
  
  # Dynamically set the URL and SHA256 based on the CPU architecture
  if Hardware::CPU.intel?
    url "https://github.com/divanvisagie/nocol/releases/download/{{tag}}/nocol-darwin-x86_64.tar.gz"
    sha256 "{{intel_hash}}"
  elsif Hardware::CPU.arm?
    url "https://github.com/divanvisagie/nocol/releases/download/{{tag}}/nocol-darwin-aarch64.tar.gz"
    sha256 "{{arm_hash}}"
  else
    odie "Your architecture is not supported!"
  end

  def install
    bin.install "nocol"
    man1.install "nocol.1"
  end

  test do
    system "#{bin}/nocol --version"
  end
end
